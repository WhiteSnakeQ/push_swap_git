/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_additional.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:28:56 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 07:49:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	calculate_move(int move_a, int move_a2, int move_b)
{
	int		all_move;
	int		full_move_a;

	full_move_a = move_a + move_a2;
	if ((full_move_a < 0 && move_b < 0) || (full_move_a > 0 && move_b > 0))
	{
		if (abc(full_move_a) > abc(move_b))
			all_move = full_move_a;
		else
			all_move = move_b;
	}
	else
		all_move = full_move_a - move_b;
	return (abc(all_move));
}

int	found_lowest(t_list_d *a, int start_list, int end_list, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (a->order >= start_list || end_list > start_list || a->order >= end_list)
		return (size * 2);
	while (i < size)
	{
		if (a->order < start_list && a->order < end_list)
			break ;
		i++;
		a = a->next;
	}
	while (abc(j) < size)
	{
		if (a->order < start_list && a->order < end_list)
			break ;
		j--;
		a = a->back;
	}
	if (abc(j) > i)
		return (i);
	else
		return (j);
}

int	found_upper(t_list_d *a, int start_list, int end_list, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (a->order <= start_list || end_list < start_list || a->order >= end_list)
		return (size * 2);
	while (i < size)
	{
		if (a->order > start_list && end_list > a->order)
			break ;
		i++;
		a = a->next;
	}
	while (abc(j) < size)
	{
		if (a->order > start_list && end_list > a->order)
			break ;
		j--;
		a = a->back;
	}
	if (abc(j) > i)
		return (i);
	else
		return (j);
}

int	choose_digit(t_stuck *a, int digit)
{
	t_list_d	*list1;
	t_list_d	*list2;
	int			go_down;
	int			go_up;

	list1 = a->first;
	list2 = a->first;
	go_down = 0;
	go_up = 0;
	while (list1->order != digit && go_down < a->act_size)
	{
		list1 = list1->next;
		go_down--;
	}
	while (list2->order != digit && go_up < a->act_size)
	{
		list2 = list2->back;
		go_up++;
	}
	if (abc(go_up) >= abc(go_down))
		return (go_down);
	else
		return (go_up);
}
