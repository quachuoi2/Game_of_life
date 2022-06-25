# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 10:44:32 by mrozhnova         #+#    #+#              #
#    Updated: 2022/06/25 12:28:45 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game_of_life
BONUS_NAME=animation
BASE= main.c parse_state.c algo.c map_handler.c abomination.c
BONUS= animation.c parse_state.c algo.c map_handler.c bonus.c abomination.c
INCLUDES= -I includes -I libft
RUN_LIB=make -C libft/ fclean && make -C libft/
OPTIMIZATION= -flto -Ofast

all: $(NAME)

$(NAME): $(SRCS)
	$(RUN_LIB)
	echo Compiling $(NAME)...
	@gcc $(INCLUDES) -o $(NAME) $(addprefix srcs/, $(BASE)) libft/libft.a -lpthread $(OPTIMIZATION)
	@gcc $(INCLUDES) -o $(BONUS_NAME) $(addprefix srcs/, $(BONUS)) libft/libft.a -lpthread $(OPTIMIZATION)
	@chmod 777 life
	@chmod 777 animated_life
	echo $(NAME) compiled succesfully!

m:
	@gcc $(INCLUDES) -o $(NAME) $(addprefix srcs/, $(BASE)) libft/libft.a -lpthread $(OPTIMIZATION)

clean:
	@/bin/rm -rf ./objs
	@/bin/rm -f $(wildcard *.o)
	@make -C libft/ clean
	@echo Clean successful!

fclean: clean
	@/bin/rm -f $(NAME) $(BONUS_NAME)
	@make -C libft/ fclean
	@echo Fclean successful!

re: fclean all
