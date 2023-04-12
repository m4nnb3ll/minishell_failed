#ifndef TOKENIZER_H
# define TOKENIZER_H

#include <readline/readline.h>
#include "libft.h"//remove this later after setting minishell.h

typedef enum e_type
{
	T_IDENTIFIER=42,
	T_SPACE, // 43
	T_S_QUOTE, // Single Quote 44
	T_D_QUOTE, // Double Quote 45
	T_IN_REDIR, // 46
	T_OUT_REDIR, // 47
	T_HEREDOC, // 48
	T_APPEND, // 49
	T_PIPE, // 50
	T_DOLLAR // 51
} t_type;

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

// TOKENIZER APPENDERS
int		ft_append_separator(t_type type, char **str_ptr, t_token **token_list);
int		ft_append_quoted_str(char **str_ptr, t_token **token_list);
int		ft_append_dollar_str(char **str, t_token **token_list);
int		ft_append_identifier(char **str_ptr, t_token **token_list);

// TOKENIZER HANDLERS
int		ft_handle_space(char **str_ptr, t_token **token_list);
int		ft_handle_quotes(char **str_ptr, t_token **token_list);
int		ft_handle_dollar(char **str, t_token **token_list);
int		ft_handle_separator(char **line, t_token **token_list);
t_token	*ft_tokenization_handler(char *line);

// TOKENIZER LIST
t_token	*ft_new_token(char *value, t_type type);
void	ft_append_token(t_token **lst, t_token *new_token);
void	ft_clear_token_list(t_token **lst);

// TOKENIZER UTILS
int		ft_is_quote(char c);
int		ft_is_separator(char c);

// TOKENIZER
t_token	*ft_tokenize(void);

#endif