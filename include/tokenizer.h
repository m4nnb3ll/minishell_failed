/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:07:14 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/11 20:08:38 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

#include <readline/readline.h>
#include "libft.h"//remove this later after setting minishell.h
#include "stdbool.h"//remove this later after setting minishell.h

#define QUOTE_ERR "Error: unclosed quotes!\n"

typedef enum e_type
{
	T_IDENTIFIER,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_PIPE,
	T_O_PARENT,
	T_C_PARENT,
	T_AND,
	T_OR
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
void	ft_skip_spaces(char **line);

// TOKENIZER
t_token	*ft_tokenize(void);

#endif