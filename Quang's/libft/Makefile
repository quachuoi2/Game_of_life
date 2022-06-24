# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 19:02:23 by qnguyen           #+#    #+#              #
#    Updated: 2022/06/24 05:20:46 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_bzero ft_memmove ft_memalloc

all: $(NAME)

$(NAME): $(addsuffix .o, $(SRCS))
	ar -rcs $(NAME) $(addsuffix .o, $(SRCS))

.c.o: $(addsuffix .c, $(SRCS)) libft.h
	gcc $(FLAGS) -c $<

clean:
	@/bin/rm -f $(wildcard *.o)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all