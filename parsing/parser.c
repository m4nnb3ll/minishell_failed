/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:55:17 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/15 15:39:02 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell.h"

char	*types[] = 
{
	"T_IDENTIFIER",
	"<",
	">",
	"<<",
	">>",
	"|",
	"OP",
	"CP",
	"&&",
	"||"
};

void	get_next_token()
{
	minishell.tokens = minishell.tokens -> next;
}

bool	is_binop(t_type type)
{
	if (type == T_PIPE || type == T_AND || type == T_OR )
		return (true);
	return (false);
}

bool	is_redir(t_type type)
{
	if (type == T_LESS || type == T_GREAT
		|| type == T_DLESS || type == T_DGREAT)
		return (true);
	return (false);
}

int	prec(t_type type)
{
	if (type == T_OR)
		return (0);
	if (type == T_AND)
		return (1);
	return (2);
}

bool	ft_get_io_list(t_io_node **io_list)
{
	t_type		redir_type;
	t_io_node	*tmp_io_node;

	while (minishell.tokens && is_redir(minishell.tokens->type))
	{
		redir_type = minishell.tokens->type;
		get_next_token();
		if (minishell.tokens->type != T_IDENTIFIER)
			return (false);//ERROR
		tmp_io_node = ft_new_io_node(redir_type, minishell.tokens->value);
		if (!tmp_io_node)
			exit(1);
		ft_append_io_node(io_list, tmp_io_node);
		get_next_token();
	}
	return (1);
}

void	ft_join_args(char **args)
{
	char	*to_free;

	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		exit(1);
	while (minishell.tokens && minishell.tokens -> type == T_IDENTIFIER)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, minishell.tokens -> value, ' ');
		if (!args)
			exit(1);
		free(to_free);
		get_next_token();
	}
}

t_node	*get_simple_cmd()
{
	t_node	*node;

	node = ft_new_node(T_CMD);
	while (minishell.tokens
		&& (minishell.tokens->type == T_IDENTIFIER || is_redir(minishell.tokens->type)))
	{
		if (minishell.tokens->type == T_IDENTIFIER)
			ft_join_args(&(node -> args));
		else if (is_redir(minishell.tokens->type))
		{
			if (!ft_get_io_list(&(node->io_list)))
			{
				printf("Syntax error near: %s\n", types[minishell.tokens->type]);
				exit(1);
			}
		}
	}
	return (node);
}

t_node	*term()
{
	t_node	*node;

	if (is_binop(minishell.tokens->type))
	{
		printf("Syntax error near: %s\n", types[minishell.tokens->type]);
		exit(1);//tmp
	}
	else if (minishell.tokens->type == T_O_PARENT)
	{
		get_next_token();
		node = expression(0);
		if (!minishell.tokens || minishell.tokens->type != T_C_PARENT)
		{
			printf("Unclosed parenthesis!\n");
			exit(1);//tmp
		}
		get_next_token();
		return (node);
	}
	else
		return get_simple_cmd();
}

t_node	*combine(t_type op, t_node *left, t_node *right)
{
	t_node	*node;

	node = ft_new_node(op);
	node -> left = left;
	node -> right = right;
	return (node);
}

t_node	*expression(int min_prec)
{
	t_node	*left;
	t_node	*right;
	int		n_prec;
	t_type	op;

	left = term();
	while (minishell.tokens && is_binop(minishell.tokens->type) && prec(minishell.tokens->type) >= min_prec)
	{
		op = minishell.tokens->type;
		get_next_token();
		n_prec = prec(op) + 1;
		right = expression(n_prec);
		left = combine(op, left, right);
	}
	return (left);
}

t_node	*ft_parse()
{
	return expression(0);
	if (!minishell.tokens)
		printf("unexpected end of file!!!\n");
}

void	print_tree(t_node *node)
{
	t_io_node	*tmp_io_node;

	if (node -> type != T_CMD)
	{
		printf("(");
		if (node -> left)
			print_tree(node -> left);
		if (is_binop(node->type))
			printf(" ");
		printf("%s", types[node->type]);
		if (is_binop(node->type))
			printf(" ");
		if (node -> right)
			print_tree(node -> right);
		printf(")");
	}
	else
	{
		printf("%s ", node->args);
		tmp_io_node = node -> io_list;
		while (tmp_io_node)
		{
			printf("%s%s", types[tmp_io_node->type], tmp_io_node->value);
			tmp_io_node = tmp_io_node -> next;
			if (tmp_io_node)
				printf(" ");
		}
	}
}

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("%s\n", types[tokens->type]);
		tokens = tokens -> next;
	}
}