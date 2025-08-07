/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:57:46 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/24 18:19:49 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_edge_cases1(argv);
	check_edge_cases2(argv);
	check_edge_cases3(argv);
	stack_a = parsing(argv);
	if (!stack_a)
		return (1);
	has_duplicates(stack_a);
	if (is_it_sorted(&stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	turkish_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
