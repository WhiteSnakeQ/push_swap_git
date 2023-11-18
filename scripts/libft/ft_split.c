/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:45:07 by kreys             #+#    #+#             */
/*   Updated: 2023/10/31 17:13:50 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	compare(char symbol, char sep)
// {
// 	int	i;

// 	i = 1;
// 	if (sep == symbol)
// 		return (i);
// 	return (-1);
// }

// char	*crt_str(const char *string, int *iteration, char sep)
// {
// 	char	*s;
// 	int		new_str;
// 	int		size_for_str;
// 	int		place;

// 	place = *iteration;
// 	new_str = 0;
// 	size_for_str = 0;
// 	while (compare(string[place], sep) < 0 && string[place])
// 	{
// 		place++;
// 		size_for_str++;
// 	}
// 	if (size_for_str <= 0)
// 		return (NULL);
// 	s = malloc(sizeof(char) * (size_for_str + 1));
// 	if (s == NULL)
// 		return (NULL);
// 	while (size_for_str-- > 0)
// 	{
// 		s[new_str++] = string[*iteration];
// 		*iteration += 1;
// 	}
// 	s[new_str] = '\0';
// 	return (s);
// }

// int	calc_size(const char *str, char sep)
// {
// 	int		i;
// 	int		count;
// 	int		flag;

// 	i = 0;
// 	count = 0;
// 	flag = 1;
// 	while (str[i])
// 	{
// 		if (compare(str[i], sep) >= 0 && str[i + 1] && i != 0 && flag == 0)
// 		{
// 			flag = 1;
// 		}
// 		if (compare(str[i], sep) < 0 && flag == 1)
// 		{
// 			flag = 0;
// 			count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

// char	**ft_split(const char *str, const char charset)
// {
// 	char	**string_to_ret;
// 	char	*new_str;
// 	int		num_str;
// 	int		iteration;

// 	iteration = 0;
// 	if (str == NULL)
// 		return (NULL);
// 	num_str = calc_size(str, charset);
// 	string_to_ret = malloc(sizeof(char *) * (num_str + 1));
// 	if (string_to_ret == NULL)
// 		return (NULL);
// 	*(string_to_ret + num_str) = 0;
// 	if (num_str <= 0)
// 		return (string_to_ret);
// 	num_str = 0;
// 	while (str[iteration])
// 	{
// 		new_str = crt_str(str, &iteration, charset);
// 		if (new_str != NULL)
// 			*(string_to_ret + num_str++) = new_str;
// 		iteration++;
// 	}
// 	return (string_to_ret);
// }

static size_t	counter(char const *s, char c)
{
	size_t	counts;

	if (!*s)
		return (0);
	counts = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			counts++;
		while (*s != c && *s)
			s++;
	}
	return (counts);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	lenss;
	int		i;

	str = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				lenss = ft_strlen(s);
			else
				lenss = ft_strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, lenss);
			s += lenss;
		}
	}
	str[i] = NULL;
	return (str);
}
