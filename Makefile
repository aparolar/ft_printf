# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:37:58 by aparolar          #+#    #+#              #
#    Updated: 2021/07/24 13:07:35 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# version for Mac

MAKE		=	make

SRCS		=	ft_printf.c\
				ft_preparse.c\
				post_parsers.c\
				printf_utils1.c\
				printf_utils2.c\
				ft_strlen.c\
				ft_longlen.c\
				ft_putchar.c\
				ft_putstr.c\
				ft_isdigit.c\
				ft_ltoa.c\
				ft_atol.c\
				ft_calloc.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc $(FLAGS) -I.

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)
				@rm -rf $(OBJS)

clean:			
				@rm -fr $(OBJS)

fclean:			clean
				@rm -fr $(NAME)

re:				clean fclean all

test:			re
				rm -rf test
				@$(CC) -L. main.c -o test -lftprintf
				@rm -rf *.o

test_asm:		all
				@$(CC) -S -O3  main.c -o $(TEST_NAME).s $(NAME)

.PHONY:			all clean fclean re
