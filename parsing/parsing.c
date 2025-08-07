/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:26:10 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/14 19:32:01 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*new_node(int n)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	return (new_node);
}

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_atol(char **nb)
{
	int		a;
	int		sign;
	long	num;

	a = 0;
	num = 0;
	while (is_space(nb[0][a]))
		a++;
	sign = (nb[0][a] != '-') - (nb[0][a] == '-');
	a += (nb[0][a] == '-') || (nb[0][a] == '+');
	while (nb[0][a] >= '0' && nb[0][a] <= '9')
	{
		if (sign)
			num = num * 10 + (nb[0][a++] - '0');
		else
			num = num * 10 - (nb[0][a++] - '0');
		if (num > INT_MAX || num < INT_MIN)
			error_exit();
	}
	while (is_space(nb[0][a]))
		a++;
	nb[0] += a;
	return ((int)(num * sign));
}

int	has_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*temp;

	current = stack;
	while (current)
	{
		temp = current;
		while (temp->next != NULL)
		{
			if (current->n == temp->next->n)
			{
				write(2, "Error\n", 6);
				free_stack(stack);
				exit(1);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

t_list	*parsing(char **argv)
{
	t_list	*begin;
	t_list	*node;
	t_list	*end;
	int		a;

	a = 1;
	begin = NULL;
	while (argv[a])
	{
		node = new_node(ft_atol(&argv[a]));
		if (begin == NULL)
			begin = node;
		else
			end->next = node;
		end = node;
		if (*argv[a] == '\0')
			a++;
		else if (!((*argv[a] >= '0' && *argv[a] <= '9') || *argv[a] == '+'
				|| *argv[a] == '-'))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	return (begin);
}
