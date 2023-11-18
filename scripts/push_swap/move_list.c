/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:31:25 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 07:27:00 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	move_act_down(t_act *act, t_stuck *a, t_stuck *b)
{
	while (act->move_a != 0 && act->move_b != 0)
	{
		push_down(a, b, 1);
		act->move_a--;
		act->move_b--;
	}
}

void	move_act_up(t_act *act, t_stuck *a, t_stuck *b)
{
	while (act->move_a != 0 && act->move_b != 0)
	{
		push_up(a, b, 1);
		act->move_a++;
		act->move_b++;
	}
}

void	move_act_one(t_act *act, t_stuck *a, t_stuck *b)
{
	while (act->move_a < 0)
	{
		act->move_a++;
		push_up(a, NULL, 0);
	}
	while (act->move_a > 0)
	{
		act->move_a--;
		push_down(a, NULL, 0);
	}
	while (act->move_b < 0)
	{
		act->move_b++;
		push_up(NULL, b, 0);
	}
	while (act->move_b > 0)
	{
		act->move_b--;
		push_down(NULL, b, 0);
	}
}

void	move_act_one_int(int digit, t_stuck *a, t_stuck *b)
{
	while (digit > 0)
	{
		digit--;
		push_down(a, b, 0);
	}
	while (digit < 0)
	{
		digit++;
		push_up(a, b, 0);
	}
}

void	make_move_stuck_b(t_stuck *b)
{
	int	go;

	go = choose_digit(b, b->max);
	move_act_one_int(go, NULL, b);
}
