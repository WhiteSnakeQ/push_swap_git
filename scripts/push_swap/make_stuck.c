/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stuck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:31:45 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 21:16:48 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_dubl(int value, t_list_d *first)
{
	t_list_d	*curr;
	char		i;

	i = 0;
	curr = first;
	while (first && (first != curr || i++ == 0))
	{
		if (curr->value == value)
			return (-1);
		curr = curr->next;
	}
	return (0);
}

int	check_real_digit(int digit, char *str)
{
	int		check;
	long	digit1;
	int		i;

	i = -1;
	digit1 = digit;
	if (*str == ' ' || *str == '-' || *str == '+')
		str++;
	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (1);
	check = parse_str(str);
	if (digit1 == check || (0 - digit1) == check)
		return (1);
	return (-1);
}

int	check_string(long *number_print, const char *symbol, int *minus)
{
	int		stop_cheking;

	stop_cheking = 0;
	if ((symbol[0] == '+' || symbol[0] == '-') && *number_print == 0)
	{
		stop_cheking++;
		if (symbol[0] == '-')
			*minus = -*minus;
		symbol++;
	}
	while (*symbol)
	{
		if (symbol[0] >= '0' && symbol[0] <= '9')
		{
			*number_print *= 10;
			*number_print += symbol[0] - 48;
			stop_cheking++;
		}
		else if (*number_print > 0)
			return (-1);
		else
			return (-1);
		symbol++;
	}
	return (1);
}

long	parse_str(const char *str)
{
	long		number_to_print;
	int			minus;

	minus = 1;
	number_to_print = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	check_string(&number_to_print, str, &minus);
	if (minus == -1)
		number_to_print = -number_to_print;
	return (number_to_print);
}

t_stuck	*make_stuck(char **strs, int start)
{
	t_stuck	*my_stuck;
	int		size;

	my_stuck = malloc(sizeof(t_stuck));
	if (!my_stuck || !strs || !*strs)
		return (my_stuck);
	size = 0;
	while (strs[size + start])
		size++;
	init_stuck(my_stuck, size, 0);
	while (strs[start])
	{
		if (create_list(parse_str(strs[start]), my_stuck) == -1 \
		|| check_real_digit(my_stuck->last->value, strs[start]) == -1)
			return (my_stuck);
		start++;
	}
	return (my_stuck);
}
