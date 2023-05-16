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

PARSING		:=	parsing/parser.c \
				parsing/parser_nodes.c \
				parsing/parser_err.c\
				# parsing/clr_test.c

SRCS		:=	$(TOKENIZING)\
				$(PARSING)\
				main.c

OBJS		:= $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -Iinclude -o $@

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@echo "libft done."

$(NAME): $(OBJS) $(LIBFT)
	gcc -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -lreadline
	echo "done"

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
