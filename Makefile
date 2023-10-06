# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 16:21:02 by nkietwee          #+#    #+#              #
#    Updated: 2023/10/03 16:16:56 by nkietwee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

# FLAGS = -Wall -Wextra -Werror
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -f

INC = minishell.h

BUILTINS_PATH = Builtins/
EXECUTE_PATH = Execute/
GET_NEXT_LINE_PATH = Get_next_line/
LIBFT_PATH = Libft/
LIBFTMINISHELL_PATH = libminishell/
PARSER_PATH = parser/

# MINISHELL_SRCS = ft_minishell.c
OPENDIR				=	-L./usr/include/readline -L./libft -L./libminishell
LIBLINK				=	-lreadline

BUILTINS_SRCS = ft_cnt_builtins.c\
				ft_getenv.c\
				main_builtin.c\
				ft_cd.c\
				ft_pwd.c\
				ft_free_buit.c\
				ft_env.c\
				ft_echo.c\
				ft_export.c\
				ft_export_util.c\
				ft_prtlinklist.c\
				ft_unset.c\
				ft_exit.c

EXECUTE_SRCS = execute.c\
			ft_cnt_execute.c\
			ft_err.c\
			ft_findchar.c\
			ft_getfile.c\
			mtpcmd.c\
			ft_heredoc.c\
			ft_check_name.c\
			ft_main_exec.c\
			ft_execve.c

GET_NEXT_LINE_SRCS = get_next_line.c\
					get_next_line_utils.c\

LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_memcmp.c ft_strncmp.c ft_atoi.c \
				ft_strlen.c  ft_bzero.c \
				ft_calloc.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_striteri.c \
				ft_strchr.c ft_strdup.c ft_strrchr.c ft_strnstr.c  \
				ft_substr.c  ft_split.c \
				ft_issign.c ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c  \
				ft_lstpop_bot.c ft_lstpop_top.c ft_atol.c ft_isspace.c ft_split_allsp.c \
				ft_freesplite.c  ft_strjoinextra.c ft_strcmp.c \
				ft_lstadd_front_dict.c ft_lstnew_dict.c ft_lstadd_back_dict.c\
				ft_lstsize_dict.c ft_memmove.c ft_memcpy.c ft_strjoin.c ft_itoa.c \


LIBFTMINISHELL_SRCS = ft_ismetachar.c ft_isquote.c

PARSER_SRCS = main.c prompt.c lexer.c grab.c init_command_list.c \
					quotes_validate.c tokenize.c paser.c \
					get_cmd_to_table.c get_rdr_to_table.c \
					exit_err.c expand_in_quote.c expand_var.c \
					scan_n_expand.c

SRCS = $(addprefix $(BUILTINS_PATH), $(BUILTINS_SRCS))\
		$(addprefix $(EXECUTE_PATH), $(EXECUTE_SRCS))\
		$(addprefix $(GET_NEXT_LINE_PATH), $(GET_NEXT_LINE_SRCS))\
		$(addprefix $(LIBFTMINISHELL_PATH), $(LIBFTMINISHELL_SRCS))\
		$(addprefix $(PARSER_PATH), $(PARSER_SRCS))\
		$(addprefix $(LIBFT_PATH), $(LIBFT_SRCS))\


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o:%c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L/usr/local/lib -I/usr/local/include -lreadline $(OBJS) -o $(NAME)

# $(CC) $(FLAGS) -L/usr/local/lib -L./usr/include -I/usr/local/include  $(OBJS) -o $(NAME) -lreadline


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
