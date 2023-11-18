/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:49:38 by kreys             #+#    #+#             */
/*   Updated: 2023/11/17 16:28:09 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "scripts/libft/libft.h"
# include "scripts/printf/ft_printf.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct s_stuck
{
	struct s_list_d		*first;
	struct s_list_d		*last;
	int					size;
	int					act_size;
	int					max;
	int					val;
	int					ord;
}	t_stuck;

typedef struct s_list_d
{
	int					value;
	int					order;
	struct s_list_d		*back;
	struct s_list_d		*next;
}	t_list_d;

typedef struct s_act
{
	int						b_counter;
	int						a_counter;
	int						c_actions;
	int						act_a;
	int						move_b;
	int						move_a;
	struct s_list_d			*list_a;
	struct s_list_d			*list_b;
}	t_act;

int		main(int argc, char **argv);

//				Parsing
t_stuck	*make_stuck(char **strs, int start, int clean);
char	*new_str(char *str);
char	**make_strs(char *str);
char	**create_strs(char *str, int size);
int		check_dubl(int value, t_list_d *first);
int		check_string(long *number_print, const char *symbol, int *minus);
int		parse_str(const char *str);
int		count_world_str(char *str);
int		check_real_digit(int digit, char *str);

//				Init_&&_create_&&_delete_obj
int		create_list(int value, t_stuck *stuck);
int		init_list(int value, t_list_d *first_l, t_list_d *last_l);
void	init_stuck(t_stuck *stuck, int size, int act_size);
void	init_action(t_act *act, t_list_d *list_a, t_list_d *list_b);
void	free_stuck(t_stuck **stuck);
void	clear_l(t_list_d **list);

//				Action_with_list
void	add_front_l(t_stuck *a, t_stuck *b);
void	push_up(t_stuck *a, t_stuck *b, int mod);
void	push_down(t_stuck *a, t_stuck *b, int mod);
void	swap(t_stuck *a, t_stuck *b, int mod);
void	push(t_stuck *a, t_stuck *b, int mod);

//				First_step_in_sort
void	give_index(t_stuck *a);
void	ft_sort_int_tab(t_list_d **tab, int size);
void	swap_list(t_list_d **digit_one, t_list_d **digit_two);

//				Start_sorting
void	sort_stucks(t_stuck *a, t_stuck *b);

//				Sort_<=_3d
void	make_tree(t_stuck *a);
void	make_tree_b(t_stuck *a);
void	make_all(t_stuck *a, t_stuck *b);
int		check_order_a(t_stuck *a);
int		check_order_b(t_stuck *a);

//				Sort_<=_6d
void	go_simple_sort(t_stuck *a, t_stuck *b);

//				Sort_>6d
t_act	*go_difficult_sort(t_stuck *a, t_stuck *b);
void	check_max(t_act *act, t_stuck *a, t_stuck *b);
void	check_lower(t_act *act, t_stuck *a, t_stuck *b);
void	cheak_hight(t_act *act, t_stuck *a, t_stuck *b);
void	compl_act(t_act *act, t_stuck *a, t_stuck *b);
int		calculate_move(int move_a, int move_a2, int move_b);
int		found_lowest(t_list_d *a, int start_list, int end_list, int size);
int		found_upper(t_list_d *a, int start_list, int end_list, int size);
int		choose_digit(t_stuck *a, int digit);

//				Move_stucks
void	make_move_stuck_b(t_stuck *b);
void	move_act_one_int(int digit, t_stuck *a, t_stuck *b);
void	move_act_one(t_act *act, t_stuck *a, t_stuck *b);
void	move_act_up(t_act *act, t_stuck *a, t_stuck *b);
void	move_act_down(t_act *act, t_stuck *a, t_stuck *b);

//				Helpers
int		abc(int a);
void	make_stuck_head(t_stuck *a, t_stuck *b);
int		check_order_a(t_stuck *a);

//				print_stuck
void	printf_stuck(t_stuck *a, t_stuck *b, int i);

#endif