/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:51:13 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 20:46:55 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_stucks(t_stuck *a, t_stuck *b)
{
	int	sorted;

	sorted = check_order_a(a);
	if (sorted == -1 || a->act_size == 1)
		return ;
	if (a->act_size <= 3)
	{
		make_tree(a);
		return ;
	}
	give_index(a);
	if (a->size <= 6)
		go_simple_sort(a, b);
	else
	{
		push(b, a, 2);
		push(b, a, 2);
		while (a->act_size > 0)
			compl_act(go_difficult_sort(a, b), a, b);
		make_move_stuck_b(b);
		make_stuck_head(a, b);
	}
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
		sort_stucks(stuck_a, stuck_b);
		free_stuck(&stuck_b);
		free_stuck(&stuck_a);
	}
	return (0);
}
