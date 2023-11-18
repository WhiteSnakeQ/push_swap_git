/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:14:06 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 07:49:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	compl_act(t_act *act, t_stuck *a, t_stuck *b)
{
	if (act->move_a < 0 && act->move_b < 0)
		move_act_up(act, a, b);
	else if (act->move_a > 0 && act->move_b > 0)
		move_act_down(act, a, b);
	move_act_one(act, a, b);
	push(b, a, 2);
	free(act);
}

void	cheak_hight(t_act *act, t_stuck *a, t_stuck *b)
{
	int		move_b;
	int		move_a;
	int		moves;

	move_b = choose_digit(b, act->list_b->order);
	move_a = choose_digit(a, act->list_a->order);
	act->act_a = found_upper(act->list_a, act->list_b->order, \
		act->list_b->back->order, a->size);
	moves = calculate_move(act->act_a, move_a, move_b);
	if (abc(moves) < abc(act->c_actions))
	{
		act->move_a = act->act_a + move_a;
		act->move_b = move_b;
		act->c_actions = moves;
	}
	act->act_a = 0;
}

void	check_lower(t_act *act, t_stuck *a, t_stuck *b)
{
	int		move_b;
	int		move_a;
	int		moves;

	move_b = choose_digit(b, act->list_b->order);
	move_a = choose_digit(a, act->list_a->order);
	act->act_a = found_lowest(act->list_a, act->list_b->order, \
		act->list_b->back->order, a->size);
	moves = calculate_move(act->act_a, move_a, move_b);
	if (abc(moves) < abc(act->c_actions))
	{
		act->move_a = act->act_a + move_a;
		act->move_b = move_b;
		act->c_actions = moves;
	}
	act->act_a = 0;
}

void	check_max(t_act *act, t_stuck *a, t_stuck *b)
{
	int		move_b;
	int		move_a;
	int		moves;

	move_b = choose_digit(b, b->max);
	move_a = choose_digit(a, act->list_a->order);
	moves = calculate_move(act->act_a, move_a, move_b);
	if (abc(moves) < abc(act->c_actions))
	{
		act->move_a = act->act_a + move_a;
		act->move_b = move_b;
		act->c_actions = moves;
	}
	act->act_a = 0;
}

t_act	*go_difficult_sort(t_stuck *a, t_stuck *b)
{
	t_act	*act;

	act = malloc(sizeof(t_act));
	init_action(act, a->first, b->first);
	act->list_b = b->first;
	while (b->act_size > act->b_counter++)
	{
		act->list_a = a->first;
		act->a_counter = 0;
		while (a->act_size > act->a_counter++)
		{
			if (act->list_a->order > b->max)
				check_max(act, a, b);
			else
			{
				cheak_hight(act, a, b);
				check_lower(act, a, b);
			}
			if (act->c_actions == 0)
				return (act);
			act->list_a = act->list_a->next;
		}
		act->list_b = act->list_b->next;
	}
	return (act);
}
