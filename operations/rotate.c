/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:25:20 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/09 22:31:43 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
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
	t_list	*temp;

	node1 = new_node(1);
	node2 = new_node(2);
	node3 = new_node(3);

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("Before rotation:\n\n");
	temp = node1;
	while (temp != NULL)
	{
		printf("%d - %p - %p\n", (int)temp->n, temp, temp->next);
		temp = temp->next;
	}

	rotate(&node1);

	printf("\nAfter rotation:\n\n");
	temp = node2;
	while (temp != NULL)
	{
		printf("%d - %p - %p\n", (int)temp->n, temp, temp->next);
		temp = temp->next;
	}
	return (0);
}*/
