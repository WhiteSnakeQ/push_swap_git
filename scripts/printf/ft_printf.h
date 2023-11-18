/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:35:20 by kreys             #+#    #+#             */
/*   Updated: 2023/11/14 11:55:34 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define ASCII_B "0123456789ABCDEF"
# define ASCII_S "0123456789abcdef"

typedef struct s_action
{
	char	*txt;
	char	act;
	int		pos;
	int		skip;
	int		padding_left;
	int		zero;
	int		plus;
	int		space;
	int		point;
	int		sharp;
	int		width;
	int		s_txt;
	int		use;
	int		s_pad;
	int		s_pnt;
	int		count;
}			t_action;

int		calculate_size(unsigned long long digit);
int		get_u_decimal_size(unsigned int digit);
int		get_decimal_size(int digit);
int		ft_printf(const char *str, ...);
int		builder(t_action act);
int		pud_build(int digit, int zero, char symb, int *iteraion);
int		check_for_hex(unsigned long long digit);
int		str_len(const char *str);

void	chenge_str(t_action *act);
void	prt_hex_adrs(void *ptr, t_action **act);
void	check_for_flags(char c, t_action **act);
void	chk_for_act(const char *str, va_list args, t_action **act);
void	put_char(char c, t_action **act);
void	put_decimal(int digit, t_action **act);
void	put_nbr(int digit, t_action **act);
void	put_hex_digit(unsigned int hex, t_action **act, int mod);
void	put_hex_sp(unsigned long long digit, t_action **act, char *convert);
void	put_str(char *str, t_action **act);
void	put_u_decimal(unsigned int digit, t_action **act);
void	put_u_nbr(unsigned int digit, t_action **act);
void	put_hex(unsigned long long digit, t_action **act, char *convert);
void	initialize(t_action **act);

char	*str_dup(char *src);
char	*add_smb_s(char *str, int size_str, int size_padd, char symb);

#endif