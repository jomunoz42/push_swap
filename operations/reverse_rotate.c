/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:25:13 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/09 22:31:39 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*node_before_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	before_last = node_before_last(last);
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	before_last->next = NULL;
	*stack = last;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
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

	node1 = new_node(2);
	node2 = new_node(3);
	node3 = new_node(1);

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

	reverse_rotate(&node1);

	printf("\nAfter rotation:\n\n");
	temp = node3;
	while (temp != NULL)
	{
		printf("%d - %p - %p\n", (int)temp->n, temp, temp->next);
		temp = temp->next;
	}
	return (0);
}*/
