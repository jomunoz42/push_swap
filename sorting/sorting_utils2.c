/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:34:13 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/09 22:32:31 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (lst_size(stack_a) != 3)
		return ;
	a = (*stack_a)->n;
	b = (*stack_a)->next->n;
	c = (*stack_a)->next->next->n;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

int	cost_to_top_by_index(t_list **stack, int index)
{
	int	cost;

	if (index <= lst_size(stack) / 2)
		cost = index;
	else
		cost = lst_size(stack) - index;
	return (cost);
}

int	is_it_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_stack_a(t_list **stack_a)
{
	int	index;
	int	size;

	if (is_it_sorted(stack_a))
		return ;
	size = lst_size(stack_a);
	index = find_node_index(stack_a, find_smallest(stack_a));
	if (index <= lst_size(stack_a) / 2)
	{
		while (index-- > 0)
			ra(stack_a);
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			rra(stack_a);
	}
}
