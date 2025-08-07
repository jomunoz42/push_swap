/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:41:52 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/24 18:17:08 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_list
{
	int				n;
	struct s_list	*next;

}					t_list;

//=======================PARSING=========================

int					has_duplicates(t_list *stack);
void				check_edge_cases1(char *argv[]);
void				check_edge_cases2(char *argv[]);
void				check_edge_cases3(char *argv[]);
t_list				*parsing(char **argv);

//======================OPERATIONS=======================

void				swap(t_list **stack);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				push(t_list **stack_src, t_list **stack_dest);
void				pa(t_list **stack_b, t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
void				rotate(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				reverse_rotate(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

//=======================SORTING=========================

int					lst_size(t_list **stack);
t_list				*find_smallest(t_list **stack);
t_list				*is_smallest_bigger(t_list **stack_a, t_list *node_b);
int					find_node_index(t_list **stack, t_list *node);
t_list				*find_node_by_index(t_list **stack, int index);
void				sort_3(t_list **stack_a);
int					cost_to_top_by_index(t_list **stack, int index);
int					is_it_sorted(t_list **stack);
void				sort_stack_a(t_list **stack_a);
void				turkish_sort(t_list **stack_a, t_list **stack_b);

//=======================UTILS===========================

char				*get_next_line(int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				free_stack(t_list *stack);
void				error_exit(void);

#endif