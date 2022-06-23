# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 10:44:32 by mrozhnova         #+#    #+#              #
#    Updated: 2022/06/24 01:47:22 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game_of_life
CFILES = main.c parse_state.c algo.c map_handler.c bonus.c bit_check.c
SRCS=$(addprefix srcs/, $(CFILES))
OBJS=$(addprefix objs/, $(notdir $(SRCS:.c=.o)))
INCLUDES= -I includes -I libft
FLAGS=-Wall -Wextra -Werror
RUN_LIB=make -C libft/ fclean && make -C libft/
OPTIMIZATION= -flto -Ofast
all: $(NAME)

$(NAME): $(SRCS)
	$(RUN_LIB)
	echo Compiling $(NAME)...
	gcc $(INCLUDES) -c $(SRCS) $(OPTIMIZATION)
	mv $(notdir $(SRCS:.c=.o)) objs
	gcc $(INCLUDES) -o $(NAME) $(OBJS) libft/libft.a $(OPTIMIZATION)
	echo $(NAME) compiled succesfully!

m:
	gcc $(INCLUDES) $(SRCS) -o $(NAME) -L libft/ -lft -L. -lftprintf $(OPTIMIZATION)

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(wildcard *.o)
	@make -C libft/ clean
	@echo Clean successful!

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo Fclean successful!

re: fclean all
