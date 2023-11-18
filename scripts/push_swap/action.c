/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:15:12 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 21:45:11 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_stuck *a, t_stuck *b, int mod)
{
	if (b->act_size <= 0)
		return ;
	add_front_l(a, b);
	b->act_size--;
	a->act_size++;
	if (b->act_size == 0)
	{
		b->first = NULL;
		b->last = NULL;
	}
	if (a->act_size == 1)
		a->max = a->first->order;
	else if (a->max < a->first->order)
		a->max = a->first->order;
	if (mod == 1)
		ft_printf("%s", (char *)PA);
	if (mod == 2)
		ft_printf("%s", (char *)PB);
}

void	swap(t_stuck *a, t_stuck *b, int mod)
{
	if (a && a->act_size >= 2)
	{
		a->val = a->first->value;
		a->ord = a->first->order;
		a->first->value = a->first->next->value;
		a->first->order = a->first->next->order;
		a->first->next->value = a->val;
		a->first->next->order = a->ord;
		if ((!b || b->act_size < 2) && mod != 5)
			ft_printf("%s", (char *)SA);
	}
	if (b && b->act_size >= 2)
	{
		b->val = b->first->value;
		b->ord = b->first->order;
		b->first->value = b->first->next->value;
		b->first->order = b->first->next->order;
		b->first->next->value = b->val;
		b->first->next->order = b->ord;
		if ((!a || a->act_size < 2) && mod != 5)
			ft_printf("%s", (char *)SB);
	}
	if (a && b && a->act_size >= 2 && b->act_size >= 2 && mod != 5)
		ft_printf("%s", (char *)SS);
}

void	push_down(t_stuck *a, t_stuck *b, int mod)
{
	if (a && a->act_size >= 1)
	{
		a->first = a->first->back;
		a->last = a->last->back;
		if (mod == 0)
			ft_printf("%s", (char *)RRA);
	}
	if (b && b->act_size >= 1)
	{
		b->first = b->first->back;
		b->last = b->last->back;
		if (mod == 0)
			ft_printf("%s", (char *)RRB);
	}
	if (mod == 1)
		ft_printf("%s", (char *)RRR);
}

void	push_up(t_stuck *a, t_stuck *b, int mod)
{
	if (a && a->act_size >= 1)
	{
		a->first = a->first->next;
		a->last = a->last->next;
		if (mod == 0)
			ft_printf("%s", (char *)RA);
	}
	if (b && b->act_size >= 1)
	{
		b->first = b->first->next;
		b->last = b->last->next;
		if (mod == 0)
			ft_printf("%s", (char *)RB);
	}
	if (mod == 1)
		ft_printf("%s", (char *)RR);
}

void	add_front_l(t_stuck *a, t_stuck *b)
{
	t_list_d	*prev;
	t_list_d	*new;

	new = b->first;
	b->first = new->next;
	b->first->back = b->last;
	b->last->next = b->first;
	if (a->first)
	{
		prev = a->first;
		a->first = new;
		new->next = prev;
		new->next->back = new;
		new->back = a->last;
		a->last->next = new;
	}
	else
	{
		a->first = new;
		a->last = new;
		new->next = new;
		new->back = new;
	}
}
