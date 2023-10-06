# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 13:50:38 by ptungbun          #+#    #+#              #
#    Updated: 2023/09/28 23:17:27 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libminishell.a
HEADER		=	libminishell.h
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra


# Note the single quotes the * exoressions. Make will incorrectly expand these otherwise.

SRCS		=	ft_ismetachar.c ft_isquote.c ft_isvalide_quote.c ft_lstnew_dict.c \
				ft_lstadd_front_dict.c ft_lstadd_back_dict.c


# Find all the .o files we want to build libft.a

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

# Build step for C source

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean:
	rm -rf $(NAME) $(OBJS) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re
