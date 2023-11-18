/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_strs_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:15:15 by kreys             #+#    #+#             */
/*   Updated: 2023/11/18 20:44:31 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**make_strs(char *str)
{
	int		size;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (check_all_str(str) == -1)
		return (NULL);
	size = count_world_str(str);
	if (size <= 0)
		return (NULL);
	return (create_strs(str, size));
}

void	connect_strs(char **start, char **cont)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (start[i])
		i++;
	while (cont[j])
		start[i++] = cont[j++];
	free(cont);
	start[i] = NULL;
}

char	**make_full_strs(char **strs)
{
	char	**strs_ret;
	int		i;
	int		size;

	size = 0;
	i = 1;
	while (strs[i])
	{
		if (check_all_str(strs[i]) == -1)
			return (NULL);
		size += (count_world_str(strs[i++]));
	}
	strs_ret = malloc(sizeof(char *) * (size + 1));
	if (!strs_ret)
		return (NULL);
	strs_ret[0] = NULL;
	i = 1;
	while (strs[i])
		connect_strs(strs_ret, make_strs(strs[i++]));
	return (strs_ret);
}
