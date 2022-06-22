# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 10:44:32 by mrozhnova         #+#    #+#              #
#    Updated: 2022/06/22 20:43:35 by mrozhnova        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=life
CFILES = main.c parse_state.c draw_test.c map_adjasment.c life.c
SRCS=$(addprefix srcs/, $(CFILES))
OBJS=$(addprefix objs/, $(notdir $(SRCS:.c=.o)))
INCLUDES= -I includes -I libft
FLAGS=-Wall -Wextra -Werror
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	@rm -rf objs
	@echo Compiling $(NAME)...
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	@mkdir objs
	@mv $(notdir $(SRCS:.c=.o)) objs
	@gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) libft/libft.a
	@echo $(NAME) compiled succesfully!

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
