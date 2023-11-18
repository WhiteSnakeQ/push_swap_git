/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:36:00 by kreys             #+#    #+#             */
/*   Updated: 2023/11/14 11:48:46 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_action	*act;
	int			iteration;
	int			size_of_letters;

	act = malloc(sizeof(t_action));
	if (!act)
		return (0);
	va_start(args, str);
	size_of_letters = 0;
	iteration = -1;
	while (str[++iteration])
	{
		if (str[iteration] == '%' && str[iteration + 1])
		{
			chk_for_act(&str[iteration + 1], args, &act);
			size_of_letters += builder(*act);
			iteration += act->skip;
		}
		else
			size_of_letters += (write(1, &str[iteration], 1));
	}
	va_end(args);
	free(act);
	return (size_of_letters);
}
