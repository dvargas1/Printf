# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 01:39:03 by dvargas           #+#    #+#              #
#    Updated: 2022/06/22 15:44:20 by dvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	ft_printf.c \
			converter.c \
			hexa.c \
			pointer.c \
			print.c
OBJS		= ${SRCS:.c=.o}
NAME		= ftprintf.a
CC			= gcc -Wall -Wextra -Werror -I. -c

%.o: %.c ft_printf.h
			${CC} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
