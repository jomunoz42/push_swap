/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:25:10 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/09 22:31:35 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_src, t_list **stack_dest)
{
	t_list	*node;

	if (!stack_src || !*stack_src)
		return ;
	node = *stack_src;
	*stack_src = node->next;
	node->next = *stack_dest;
	*stack_dest = node;
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
/*
static t_list	*new_node(int nbr)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->n = nbr;
	new_node->next = NULL;
	return (new_node);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*tmp;

	t_list	*b1;
	t_list	*b2;
	t_list	*b3;

	node1 = new_node(1);
	node2 = new_node(2);
	node3 = new_node(3);

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	b1 = new_node(4);
	b2 = new_node(5);
	b3 = new_node(6);

	b1->next = b2;
	b2->next = b3;
	b3->next = NULL;

	ft_pa(&b1, &node1);

	tmp = node1;
	while (tmp)
	{
		printf("%d\n", (int)tmp->n);
		tmp = tmp->next;
	}
	printf("\n");

	tmp = b1;
	while (tmp)
	{
		printf("%d\n", (int)tmp->n);
		tmp = tmp->next;
	}

	return (0);
} */
