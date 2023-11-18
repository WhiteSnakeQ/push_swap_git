/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:54:43 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 18:59:42 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**check_all_strs(char **strs)
{
	int	i;

	i = 1;
	while (strs[i])
		if (check_all_str(strs[i++]) == -1)
			return (NULL);
	return (strs);
}

void	make_tree(t_stuck *a)
{
	int	go;

	if (a->first->value > a->first->next->value)
		swap(a, NULL, 0);
	if (a->first->value > a->first->next->value)
		push_down(a, NULL, 0);
	go = check_order_a(a);
	if (go == -1)
		return ;
	if (a->first->value < a->first->next->value)
		push_down(a, NULL, 0);
	go = check_order_a(a);
	if (go == -1)
		return ;
	if (a->first->value > a->first->next->value)
		swap(a, NULL, 0);
}

void	make_tree_b(t_stuck *b)
{
	int	go;

	if (b->first->value < b->first->next->value)
		swap(NULL, b, 0);
	if (b->first->value < b->first->next->value)
		push_down(NULL, b, 0);
	go = check_order_b(b);
	if (go == -1)
		return ;
	if (b->first->value > b->first->next->value)
		push_down(NULL, b, 0);
	go = check_order_b(b);
	if (go == -1)
		return ;
	if (b->first->value < b->first->next->value)
		swap(b, NULL, 0);
}

void	make_stuck_head(t_stuck *a, t_stuck *b)
{
	push(a, b, 1);
	if (b->act_size > 0)
		make_stuck_head(a, b);
}

int	abc(int a)
{
	if (a < 0)
		return ((-a));
	else
		return (a);
}
