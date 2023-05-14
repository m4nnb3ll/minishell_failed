NAME		:= minishell

LIBFT		:= libft.a
LIBFT_PATH	:= "libraries/libft"

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g

TOKENIZER	:=	tokenizer/tokenizer_appenders.c \
				tokenizer/tokenizer_lst.c \
				tokenizer/tokenizer_utils.c \
				tokenizer/tokenizer_handlers.c \
				tokenizer/tokenizer.c \

PARSER		:=	parser/parser.c \
				parser/parser_test.c \
				parser/parser_nodes.c \
				# parser/clr_test.c

SRCS		:=	$(TOKENIZER)\
				$(PARSER)

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
