# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 10:44:32 by mrozhnova         #+#    #+#              #
#    Updated: 2022/06/23 15:35:03 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game_of_life
CFILES = main.c parse_state.c free.c algo.c map_handler.c bonus.c bit_check.c
SRCS=$(addprefix srcs/, $(CFILES))
OBJS=$(addprefix objs/, $(notdir $(SRCS:.c=.o)))
INCLUDES= -I includes -I libft
FLAGS=-Wall -Wextra -Werror
MLX=-I /usr/local/include -L /usr/local/lib/ -lmlx -framework -L minilibx
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME): $(SRCS)
	$(RUN_LIB)
	echo Compiling $(NAME)...
	gcc $(INCLUDES) -c $(SRCS)
	mv $(notdir $(SRCS:.c=.o)) objs
	gcc $(INCLUDES) -o $(NAME) $(OBJS) libft/libft.a
	echo $(NAME) compiled succesfully!

m:
	gcc $(INCLUDES) $(SRCS) -o $(NAME) -L libft/ -lft -L. -lftprintf

clean:
	@/bin/rm -f $(OBJS)
	@rm -rf objs
	@make -C libft/ clean
	@echo Clean successful!

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo Fclean successful!

re: fclean all
