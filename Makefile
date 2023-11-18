# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 01:07:43 by kreys             #+#    #+#              #
#    Updated: 2023/11/18 21:57:53 by kreys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATHM		= scripts/push_swap/
BPATH		= scripts/checker/
GNLP		= scripts/get_next_line/
PPNTF		= scripts/printf/

PNTF		= aditional_func.c ft_printf.c print_type.c print_hex_address.c put_decimal.c \
			put_hex_digit.c put_str.c put_u_decimall.c put_char.c builder.c
SRC			= delete_obj.c difficult_additional.c difficult_sort.c helpers.c init_obj.c make_strs.c make_stuck.c \
				move_list.c simple_sort.c sort_list.c testing.c action.c push_swap.c make_strs_m.c ft_strncmp.c
CHECK		= checker.c 
BSRC		= action.c delete_obj.c  init_obj.c make_strs.c make_stuck.c testing.c make_strs_m.c ft_strncmp.c
GNLS		= get_next_line.c get_next_line_utils.c

OBJ			= ${addprefix $(PATHM), ${SRC:.c=.o}}
BOBJ		= ${addprefix $(BPATH), ${CHECK:.c=.o}} ${addprefix ${PATHM}, ${BSRC:.c=.o}}
GNL			= ${addprefix $(GNLP), ${GNLS:.c=.o}}
PNTFO		= ${addprefix $(PPNTF), ${PNTF:.c=.o}}

MAINOBJ		= ${OBJ} ${PNTFO} 
ALLOBJ		= ${BOBJ} ${GNL} ${PNTFO} 

NAME_B		= checker

NAME_F		= push_swap

HEADER		= push_swap.h

AR			= ar rc

RM			= rm -f

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

all:		${NAME_F}

${NAME_F}:	${MAINOBJ}
			@${GCC} ${CFLAGS} ${MAINOBJ} -o ${NAME_F}

bonus:		${ALLOBJ}
			@${GCC} ${CFLAGS} ${ALLOBJ} -o ${NAME_B}

clean:
			@rm -f ${ALLOBJ} ${MAINOBJ}

fclean:		clean
			@rm -f ${NAME_F} ${NAME_B}

re:			fclean all bonus

.PHONY:		all clean fclean bonus re
