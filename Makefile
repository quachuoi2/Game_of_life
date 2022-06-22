# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 10:44:32 by mrozhnova         #+#    #+#              #
#    Updated: 2022/06/22 16:32:11 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game_of_life
CFILES = main.c parse_state.c draw_test.c
SRCS=$(addprefix srcs/, $(CFILES))
OBJS=$(addprefix objs/, $(notdir $(SRCS:.c=.o)))
INCLUDES= -I includes -I libft
FLAGS=-Wall -Wextra -Werror
MLX=-I /usr/local/include -L /usr/local/lib/ -lmlx -framework -L minilibx
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	@rm -rf objs
	@echo Compiling $(NAME)...
	@gcc -g $(INCLUDES) -c $(SRCS)
	@mkdir objs
	@mv $(notdir $(SRCS:.c=.o)) objs
	@gcc -g $(INCLUDES) -o $(NAME) $(OBJS) libft/libft.a
	@echo $(NAME) compiled succesfully!

m:
	gcc $(INCLUDES) $(SRCS) -o $(NAME) -L libft/ -lft

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
