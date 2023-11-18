/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:50:56 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 16:34:21 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	make_full(t_stuck *a, t_stuck *b)
{
	int	i;

	i = b->act_size;
	while (b->act_size > 0)
		push(a, b, 1);
	while (i-- > 0)
		push_up(a, NULL, 0);
}

void	go_simple_sort(t_stuck *a, t_stuck *b)
{
	while (a->act_size > 3)
	{
		if (a->first->order > a->size / 2)
			push(b, a, 2);
		else
			push_down(a, NULL, 0);
	}
	make_tree(a);
	make_tree_b(b);
	make_full(a, b);
}
