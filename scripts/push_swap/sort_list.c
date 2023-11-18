/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:48:14 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 07:26:43 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_list(t_list_d **digit_one, t_list_d **digit_two)
{
	t_list_d		*intermidiate;

	intermidiate = *digit_one;
	*digit_one = *digit_two;
	*digit_two = intermidiate;
}

void	ft_sort_int_tab(t_list_d **tab, int size)
{
	int		iteraion_of_array;
	int		main_iteration;
	int		increase;

	main_iteration = size;
	while (main_iteration > 0)
	{
		iteraion_of_array = size - 1;
		increase = size;
		while (iteraion_of_array >= 0)
		{
			if (tab[main_iteration - 1]->value > tab[iteraion_of_array]->value)
			{
				swap_list(&tab[main_iteration - 1],
					&tab[iteraion_of_array]);
			}
			iteraion_of_array--;
		}
		main_iteration--;
	}
}

void	give_index(t_stuck *a)
{
	t_list_d	**lists;
	t_list_d	*curr;
	int			i;

	i = 0;
	lists = malloc(sizeof(t_list_d *) * a->size);
	curr = a->first;
	while (i < a->size)
	{
		lists[i++] = curr;
		curr = curr->next;
	}
	ft_sort_int_tab(lists, a->size);
	i = 0;
	while (i < a->size)
	{
		lists[i]->order = i + 1;
		i++;
	}
	free(lists);
}
