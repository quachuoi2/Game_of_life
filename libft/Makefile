# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 16:23:50 by mrozhnova         #+#    #+#              #
#    Updated: 2022/06/23 16:41:16 by mrozhnova        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

FUNCTIONS	=	ft_strlen		\
				ft_isalpha		\
				ft_isdigit		\
				ft_isalnum		\
				ft_isascii		\
				ft_isprint		\
\
				ft_toupper		\
				ft_tolower		\
				ft_memchr		\
				ft_strchr		\
				ft_strrchr		\
				ft_bzero		\
\
				ft_memcpy		\
				ft_strcpy		\
				ft_strcat		\
				ft_strcmp		\
				ft_strstr		\
				ft_memmove		\
				ft_memcmp		\
\
				ft_strlcat		\
				ft_strdup		\
				ft_atoi			\
				ft_memccpy		\
				ft_strnstr		\
				ft_strncmp		\
				ft_strncpy		\
				ft_strncat		\
\
				ft_memalloc		\
				ft_putchar		\
				ft_putstr		\
				ft_putendl		\
				ft_putnbr		\
				ft_strnew		\
				ft_strdel		\
				ft_strclr		\
				ft_strequ		\
				ft_strnequ		\
				ft_strsub		\
				ft_strjoin		\
				ft_putchar_fd	\
				ft_putstr_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd	\
\
				ft_memdel		\
				ft_striter		\
				ft_striteri		\
				ft_strmap		\
				ft_strmapi		\
				ft_strtrim		\
				ft_strsplit		\
				ft_itoa			\
\
				ft_memset		\
\
				ft_whitespace	\
				ft_strlcpy		\
				ft_count_words	\
				ft_count_len	\
				ft_isspace		\
\
				ft_lstnew		\
				ft_lstdelone	\
				ft_lstdel		\
				ft_lstadd		\
				ft_lstiter		\
				ft_lstmap		\
				ft_strcatfree	\
				ft_itoa_double	\
				ft_itoa_base_ul	\
				ft_strjoinfree


FILES = $(patsubst %, %.c, $(FUNCTIONS))
OBJS = $(patsubst %, %.o, $(FUNCTIONS))

all: $(NAME)

$(NAME): $(FILES)
	@$(CC) $(FLAGS) -c $(FILES)
	@ar rcs $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
