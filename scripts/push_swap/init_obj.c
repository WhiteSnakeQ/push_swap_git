/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:09:08 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 07:49:28 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	init_action(t_act *act, t_list_d *list_a, t_list_d *list_b)
{
	act->act_a = 0;
	act->c_actions = 2147483647;
	act->move_a = 0;
	act->move_b = 0;
	act->b_counter = 0;
	act->a_counter = 0;
	act->list_a = list_a;
	act->list_b = list_b;
}

void	init_stuck(t_stuck *stuck, int size, int act_size)
{
	stuck->size = size;
	stuck->act_size = act_size;
	stuck->max = 0;
	stuck->first = NULL;
	stuck->last = NULL;
}

int	init_list(int value, t_list_d *first_l, t_list_d *last_l)
{
	t_list_d	*new;

	if (first_l && last_l)
	{
		new = malloc(sizeof(t_list_d));
		if (!new)
			return (-1);
		last_l->next = new;
		first_l->back = new;
		new->back = last_l;
		new->next = first_l;
		last_l = new;
	}
	else
	{
		if (!first_l)
			return (-1);
		first_l->back = first_l;
		first_l->next = first_l;
		last_l = first_l;
	}
	last_l->value = value;
	return (1);
}

int	create_list(int value, t_stuck *stuck)
{
	static int	counter = 0;
	int			check;

	if (counter == 0)
		stuck->first = malloc(sizeof(t_list_d));
	else if (check_dubl(value, stuck->first) == -1)
		return (-1);
	check = init_list(value, stuck->first, stuck->last);
	if (counter == 0)
		stuck->last = stuck->first;
	else
		stuck->last = stuck->last->next;
	counter++;
	return (check);
}
