/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:58:02 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 21:48:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "../get_next_line/get_next_line.h"

int	make_action(t_stuck *a, t_stuck *b, char *act)
{
	if (ft_strncmp(act, RRR, 5) == 0)
		push_down(a, b, 5);
	else if (ft_strncmp(act, RRA, 5) == 0)
		push_down(a, NULL, 5);
	else if (ft_strncmp(act, RRB, 5) == 0)
		push_down(NULL, b, 5);
	else if (ft_strncmp(act, RR, 5) == 0)
		push_up(a, b, 5);
	else if (ft_strncmp(act, RB, 5) == 0)
		push_up(NULL, b, 5);
	else if (ft_strncmp(act, RA, 5) == 0)
		push_up(a, NULL, 5);
	else if (ft_strncmp(act, PB, 5) == 0)
		push(b, a, 5);
	else if (ft_strncmp(act, PA, 5) == 0)
		push(a, b, 5);
	else if (ft_strncmp(act, SS, 5) == 0)
		swap(a, b, 5);
	else if (ft_strncmp(act, SA, 5) == 0)
		swap(a, NULL, 5);
	else if (ft_strncmp(act, SB, 5) == 0)
		swap(NULL, b, 5);
	else
		return (-1);
	return (0);
}

int	make_work(t_stuck *a, t_stuck *b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (make_action(a, b, str) == -1)
		{
			free(str);
			return (-1);
		}
		free(str);
		str = get_next_line(0);
	}
	if (check_order_a(a) == -1 && b->act_size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_stuck	*stuck_a;
	t_stuck	*stuck_b;
	char	**strs;

	if (argc <= 1)
		return (0);
	strs = make_full_strs(argv);
	stuck_a = make_stuck(strs, 0);
	if (!strs || strs[stuck_a->act_size] != NULL)
		free_stuck(&stuck_a);
	clean_strs(strs);
	if (!stuck_a)
		write(2, "Error\n", 6);
	else
	{
		stuck_b = malloc(sizeof(t_stuck));
		if (!stuck_b)
			write(2, "Error\n", 6);
		init_stuck(stuck_b, stuck_a->size, 0);
		if (make_work(stuck_a, stuck_b) == -1)
			write(2, "Error\n", 6);
		free_stuck(&stuck_b);
		free_stuck(&stuck_a);
	}
	return (0);
}
