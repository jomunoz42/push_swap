/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:25:15 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/09 22:31:47 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (!stack || !(*stack) || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
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

	node1 = new_node(1);
	node2 = new_node(2);
	node3 = new_node(3);

	node1->next = node2;
	node2->next = node3;
	node1->next->next->next = NULL;

	printf("%d - %p - %p\n", (int)node1->n, node1, node1->next);
	printf("%d - %p - %p\n", (int)node2->n, node2, node2->next);
	printf("%d - %p - %p\n\n", (int)node3->n, node3, node3->next);

	ft_swap(&node1);

	printf("%d - %p - %p\n", (int)node1->n, node1, node1->next);
	printf("%d - %p - %p\n", (int)node2->n, node2, node2->next);
	printf("%d - %p - %p\n", (int)node3->n, node3, node3->next);

	return (0);
}*/
