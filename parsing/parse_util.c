/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomunoz <jomunoz@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:44:25 by jomunoz           #+#    #+#             */
/*   Updated: 2025/07/24 18:18:00 by jomunoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

void	check_edge_cases1(char *argv[])
{
	int	a;

	a = 1;
	while (argv[a])
	{
		if (argv[a][0] == '\0')
			error_exit();
		a++;
	}
}

void	check_edge_cases2(char *argv[])
{
	int	a;
	int	b;

	a = 1;
	while (argv[a])
	{
		b = 0;
		while (argv[a][b])
		{
			while (argv[a][b] == ' ')
				b++;
			if (argv[a][b] == '\0')
				break ;
			if (argv[a][b] == '+' || argv[a][b] == '-')
				b++;
			if (!ft_isdigit(argv[a][b]))
				error_exit();
			while (ft_isdigit(argv[a][b]))
				b++;
			if (argv[a][b] != ' ' && argv[a][b] != '\0')
				error_exit();
		}
		a++;
	}
}

void	check_edge_cases3(char *argv[])
{
	int	a;
	int	b;

	a = 1;
	while (argv[a])
	{
		b = 0;
		while (argv[a][b])
		{
			while (argv[a][b] == 32)
			{
				b++;
				if (argv[a][b] == '\0')
					error_exit();
			}
			b++;
		}
		a++;
	}
}
