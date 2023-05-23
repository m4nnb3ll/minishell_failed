NAME		:= minishell

LIBFT		:= libft.a
LIBFT_PATH	:= "libraries/libft"

CC			:= cc

CFLAGS		:= -Wall -Werror -Wextra -g

TOKENIZING	:=	tokenizing/tokenizer_appenders.c \
				tokenizing/tokenizer_lst.c \
				tokenizing/tokenizer_utils.c \
				tokenizing/tokenizer_handlers.c \
				tokenizing/tokenizer.c \

PARSING		:=	parsing/parser_clear.c \
				parsing/parser_err.c \
				parsing/parser_helpers.c \
				parsing/parser_nodes.c \
				parsing/parser_utils.c \
				parsing/parser.c \

ENV			:=	env/add_node.c \
				env/get_env_list.c \
				env/get_node.c \
				env/new_node.c \
				env/get_value.c \
				env/get_key.c \
				env/change_value.c \
				env/env_clear.c

EXEC		:=	exec/exec.c \
				exec/path_getter.c \
				exec/cmd_getter.c \
				exec/exec_redirect.c \
				exec/exec_pipe.c \
				exec/exec_child.c\
				exec/error_msg.c\
				exec/exit_status.c\
				exec/close_fds.c\
				exec/exec_utils.c\
				exec/traverse_tree.c\

BUILTINS	:=	builtins/echo.c \
				builtins/cd.c \
				builtins/exit.c \
				builtins/pwd.c \
				builtins/export.c \
				builtins/unset.c \
				builtins/env.c

EXPANDER	:= expander/expander.c


SRCS		:=	$(TOKENIZING)\
				$(PARSING)\
				$(ENV)\
				$(EXEC)\
				$(BUILTINS)\
				$(EXPANDER)\
				main.c

OBJS		:= $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -Iinclude -o $@

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@echo "libft done."

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -lreadline
	echo "done"

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
