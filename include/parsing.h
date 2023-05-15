/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:42:22 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/15 23:45:46 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define SYNTAX_ERROR "bash: syntax error near unexpected token `%s'"

typedef enum e_parse_err_type
{
	E_MEM = 1,
	E_SYNTAX
}	t_parse_err_type;

typedef struct s_io_node
{
	t_token_type				type;
	char				*value;
	struct s_io_node	*prev;
	struct s_io_node	*next;
}	t_io_node;

typedef struct s_node
{
	t_token_type				type;
	t_io_node			*io_list;
	char				*args;
	struct s_node		*left;
	struct s_node		*right;
}	t_node;

typedef struct s_parse_err
{
	t_parse_err_type	type;
	char				*str;
}	t_parse_err;

t_node		*ft_new_node(t_token_type type);
t_io_node	*ft_new_io_node(t_token_type type, char *value);
void		ft_append_io_node(t_io_node **lst, t_io_node *new);
void		get_next_token();
bool		is_binop(t_token_type type);
bool		is_redir(t_token_type type);
int			prec(t_token_type type);
bool		ft_get_io_list(t_io_node **io_list);
bool		ft_join_args(char **args);
t_node		*get_simple_cmd();
t_node		*term();
t_node		*combine(t_token_type op, t_node *left, t_node *right);
t_node		*expression(int min_prec);
t_node		*ft_parse();
void		print_tree(t_node *node);
void		print_tokens(t_token *tokens);
void		ft_set_parse_err(t_parse_err_type type);

#endif