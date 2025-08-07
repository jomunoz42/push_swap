/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:02:13 by jomunoz           #+#    #+#             */
/*   Updated: 2025/08/05 18:50:32 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_with_smart_rotations(t_list **stack_a, t_list **stack_b,
		t_list *node)
{
	int	cost;
	int	index_a;
	int	index_b;

	cost = 0;
	index_b = find_node_index(stack_b, node);
	index_a = find_node_index(stack_a, is_smallest_bigger(stack_a, node));
	if ((index_a <= lst_size(stack_a) / 2 && index_b <= lst_size(stack_b) / 2)
		|| (index_a > lst_size(stack_a) / 2 && index_b > lst_size(stack_b) / 2))
	{
		if (index_a > lst_size(stack_a) / 2 && index_b > lst_size(stack_b) / 2)
		{
			index_a = lst_size(stack_a) - index_a;
			index_b = lst_size(stack_b) - index_b;
		}
		while (index_a > 0 && index_b > 0)
		{
			cost++;
			index_a--;
			index_b--;
		}
	}
	cost += cost_to_top_by_index(stack_a, index_a);
	cost += cost_to_top_by_index(stack_b, index_b);
	return (cost);
}

static int	index_of_cheapest_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	int		cost;
	int		cost_last;
	int		index;
	int		a;

	temp_b = *stack_b;
	index = 0;
	a = 0;
	cost_last = INT_MAX;
	while (temp_b)
	{
		cost = cost_with_smart_rotations(stack_a, stack_b, temp_b);
		if (cost < cost_last)
		{
			index = a;
			cost_last = cost;
		}
		a++;
		temp_b = temp_b->next;
	}
	return (index);
}

static void	execute_operations_to_top2(t_list **stack_a, t_list **stack_b,
		int index_a, int index_b)
{
	if (index_a <= lst_size(stack_a) / 2)
	{
		while (index_a-- > 0)
			ra(stack_a);
	}
	else
	{
		while (index_a++ < lst_size(stack_a))
			rra(stack_a);
	}
	if (index_b <= lst_size(stack_b) / 2)
	{
		while (index_b-- > 0)
			rb(stack_b);
	}
	else
	{
		while (index_b++ < lst_size(stack_b))
			rrb(stack_b);
	}
}

static void	execute_operations_to_top(t_list **stack_a, t_list **stack_b,
		int index_a, int index_b)
{
	if (index_a <= lst_size(stack_a) / 2 && index_b <= lst_size(stack_b) / 2)
	{
		while (index_a > 0 && index_b > 0)
		{
			rr(stack_a, stack_b);
			index_a--;
			index_b--;
		}
	}
	else if (index_a > lst_size(stack_a) / 2 && index_b > lst_size(stack_b) / 2)
	{
		while (index_a < lst_size(stack_a) && index_b < lst_size(stack_b))
		{
			rrr(stack_a, stack_b);
			index_a++;
			index_b++;
		}
	}
	execute_operations_to_top2(stack_a, stack_b, index_a, index_b);
}

void	turkish_sort(t_list **stack_a, t_list **stack_b)
{
	int	index_a;
	int	index_b;

	index_b = 0;
	while (lst_size(stack_a) > 3)
	{
		if (is_it_sorted(stack_a))
			break ;
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		index_b = index_of_cheapest_node(stack_a, stack_b);
		index_a = find_node_index(stack_a, is_smallest_bigger(stack_a,
					find_node_by_index(stack_b, index_b)));
		execute_operations_to_top(stack_a, stack_b, index_a, index_b);
		pa(stack_b, stack_a);
	}
	sort_stack_a(stack_a);
}
