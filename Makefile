# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 01:39:03 by dvargas           #+#    #+#              #
#    Updated: 2022/06/25 11:02:07 by dvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	ft_printf.c \
			converter.c \
			hexa.c \
			pointer.c \
			print.c
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= cc -Wall -Wextra -Werror -I. -c

%.o: %.c ft_printf.h
			@ echo 'Criando os .o com CC a partir dos .c:'
			${CC} ${SRCS}
			@ echo ' '

$(NAME):	${OBJS}
			@ echo 'Update no .a se necessário'
			ar rcs ${NAME} ${OBJS}
			@ echo ' '

all:		${NAME}

clean:
			@ echo 'Aplicando regra clean'
			rm -f ${OBJS}
			@ echo ' '

fclean:		clean
			@ echo 'Removendo o .a'
			rm -f ${NAME}
			@ echo ' '

re:			fclean all
			@ echo 'Refazendo a regra fclean, recompilando e criando o .a$<'
			@ echo ' '

.PHONY:		all clean fclean re
