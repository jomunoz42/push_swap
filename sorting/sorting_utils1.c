/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:33:47 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/09 22:32:28 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list **stack)
{
	t_list	*temp;
	int		count;

	temp = *stack;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

t_list	*find_smallest(t_list **stack)
{
	t_list	*temp;
	t_list	*node;

	node = NULL;
	temp = *stack;
	while (temp)
	{
		if (!node || temp->n < node->n)
			node = temp;
		temp = temp->next;
	}
	return (node);
}

t_list	*is_smallest_bigger(t_list **stack_a, t_list *node_b)
{
	t_list	*node;
	t_list	*temp;

	node = NULL;
	temp = *stack_a;
	while (temp)
	{
		if (temp->n > node_b->n)
		{
			if (!node || temp->n < node->n)
				node = temp;
		}
		temp = temp->next;
	}
	if (!node)
		return (find_smallest(stack_a));
	return (node);
}

int	find_node_index(t_list **stack, t_list *node)
{
	t_list	*temp;
	int		count;

	if (!node)
		return (-1);
	temp = *stack;
	count = 0;
	while (temp)
	{
		if (temp == node)
			return (count);
		count++;
		temp = temp->next;
	}
	return (-1);
}

t_list	*find_node_by_index(t_list **stack, int index)
{
	t_list	*target_node;
	int		count;

	if (index >= lst_size(stack) || index < 0)
		return (NULL);
	count = 0;
	target_node = *stack;
	while (target_node)
	{
		if (count == index)
			return (target_node);
		count++;
		target_node = target_node->next;
	}
	return (NULL);
}
