# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 01:07:43 by kreys             #+#    #+#              #
#    Updated: 2023/11/17 16:54:22 by kreys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATHM		= scripts/push_swap/
BPATH		= scripts/checker/
GNLP		= scripts/get_next_line/

PRJ			= scripts/libft/libft.a scripts/printf/libftprintf.a

SRC			= delete_obj.c difficult_additional.c difficult_sort.c helpers.c init_obj.c make_strs.c make_stuck.c move_list.c simple_sort.c sort_list.c testing.c action.c push_swap.c
CHECK		= checker.c 
BSRC		= action.c delete_obj.c  init_obj.c make_strs.c make_stuck.c testing.c 
GNLS		= get_next_line.c get_next_line_utils.c

OBJ			= ${addprefix $(PATHM), ${SRC:.c=.o}}
BOBJ		= ${addprefix $(BPATH), ${CHECK:.c=.o}} ${addprefix ${PATHM}, ${BSRC:.c=.o}}
GNL			= ${addprefix $(GNLP), ${GNLS:.c=.o}}

NAME_B		= checker

NAME_F		= push_swap

HEADER		= push_swap.h

AR			= ar rc

RM			= rm -f

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

all:		${NAME_F}

${NAME_F}:	${OBJ}
			@${GCC} ${CFLAGS} ${OBJ} ${PRJ} -o ${NAME_F}

bonus:		${OBJ} ${BOBJ} ${GNL}
			@${GCC} ${CFLAGS} ${BOBJ} ${GNL}  ${PRJ} -o ${NAME_B}

clean:
			@rm -f ${OBJ} ${BOBJ}

fclean:		clean
			@rm -f ${NAME_F} ${NAME_B}

re:			fclean all bonus

.PHONY:		all clean fclean bonus re
