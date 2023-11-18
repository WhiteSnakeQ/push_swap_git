/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:31:45 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 21:23:17 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*new_str(char *str)
{
	char	*new_str;
	int		size;
	int		i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		i++;
	new_str = malloc(sizeof(char) * (i + 1));
	new_str[i] = '\0';
	size = -1;
	while (i > ++size)
		new_str[size] = str[size];
	return (new_str);
}

char	**create_strs(char *str, int size)
{
	char	**strs;
	int		digit;
	int		i;

	digit = 0;
	i = 0;
	if (size <= 0)
		return (NULL);
	strs = malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (NULL);
	strs[size] = NULL;
	while (str && str[i] && size > digit)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			strs[digit++] = new_str(&str[i]);
			while (str[i] && (str[i] != ' ' || str[i] == ','))
				i++;
			i++;
		}
		else if (str[i] == ',')
			i++;
	}
	return (strs);
}

int	count_world_str(char *str)
{
	int	i;
	int	space;
	int	count_size;

	space = 1;
	i = 0;
	count_size = 0;
	while (str[i] == ' ')
		i++;
	while (str && str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && space == 1))
		{
			if (space == 1)
				count_size++;
			space = 0;
		}
		else if (str[i] == ' ' || str[i] == ',')
			space = 1;
		else
			return (0);
		i++;
	}
	return (count_size);
}

int	check_all_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-' \
			|| str[i] == ',')
			i++;
		else if (str[i] != '\0')
			return (-1);
	}
	return (0);
}
