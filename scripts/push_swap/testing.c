/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:15:36 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 16:24:45 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	printf_stuck(t_stuck *a, t_stuck *b, int i)
{
	t_list_d	*list;
	t_list_d	*list2;

	if (!a->first)
		return ;
	list = a->first;
	list2 = b->first;
	while (++i == 0 || (a->first != list || b->first != list2))
	{
		if (i < a->act_size)
		{
			ft_printf("{stuck_a- %d -order- %d}", list->value, list->order);
			list = list->next;
		}
		if (i < b->act_size)
		{
			if (i < a->act_size)
				ft_printf(" --- ");
			else
				ft_printf("                            ");
			ft_printf("{stuck_b- %d -order- %d}", list2->value, list2->order);
			list2 = list2->next;
		}
		ft_printf("\n");
	}
}

int	check_order_a(t_stuck *a)
{
	t_list_d	*list;
	t_list_d	*check_d;
	int			i;

	i = 0;
	if (a->act_size == 0)
		return (-2);
	list = a->first;
	check_d = list->next;
	while (i == 0 || (list != a->first && check_d != a->first))
	{
		if (list->value < check_d->value)
		{
			list = list->next;
			check_d = check_d->next;
			i++;
		}
		else
			return (i);
	}
	return (-1);
}

int	check_order_b(t_stuck *a)
{
	t_list_d	*list;
	t_list_d	*check_d;
	int			i;

	i = 0;
	if (a->act_size == 0)
		return (-2);
	list = a->first;
	check_d = list->next;
	while (i == 0 || (list != a->first && check_d != a->first))
	{
		if (list->value > check_d->value)
		{
			list = list->next;
			check_d = check_d->next;
			i++;
		}
		else
			return (i);
	}
	return (-1);
}
