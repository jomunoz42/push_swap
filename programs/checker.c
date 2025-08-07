/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:35:38 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/24 18:23:56 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ops_swap_push(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		swap(stack_a);
	if (ft_strncmp(line, "sb\n", 4) == 0)
		swap(stack_b);
	if (ft_strncmp(line, "ss\n", 4) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (ft_strncmp(line, "pa\n", 4) == 0)
		push(stack_b, stack_a);
	if (ft_strncmp(line, "pb\n", 4) == 0)
		push(stack_a, stack_b);
}

static void	ops_rotate_rrotate(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		rotate(stack_a);
	if (ft_strncmp(line, "rb\n", 4) == 0)
		rotate(stack_b);
	if (ft_strncmp(line, "rr\n", 4) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(stack_a);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(stack_b);
	if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		error_exit();
}

static void	accept_input(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		ops_swap_push(line, stack_a, stack_b);
		ops_rotate_rrotate(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
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
	accept_input(&stack_a, &stack_b);
	if (is_it_sorted(&stack_a))
		return (write(1, "OK\n", 3), free_stack(stack_a), free_stack(stack_b),
			0);
	else
		return (write(1, "KO\n", 3), free_stack(stack_a), free_stack(stack_b),
			1);
}
