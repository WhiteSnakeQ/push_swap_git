/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 06:54:20 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 16:34:44 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	clear_l(t_list_d **list)
{
	t_list_d	*curr;

	curr = (*list)->next;
	while (*list != curr)
	{
		curr = curr->next;
		free(curr->back);
	}
	free(*list);
}

void	free_stuck(t_stuck **stuck)
{
	if ((*stuck)->act_size > 0)
		clear_l(&(*stuck)->first);
	free(*stuck);
}
