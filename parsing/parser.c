/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:55:17 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/16 00:00:47 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_next_token()
{
	g_minishell.curr_token = g_minishell.curr_token -> next;
}

bool	is_binop(t_token_type type)
{
	if (type == T_PIPE || type == T_AND || type == T_OR )
		return (true);
	return (false);
}

bool	is_redir(t_token_type type)
{
	if (type == T_LESS || type == T_GREAT
		|| type == T_DLESS || type == T_DGREAT)
		return (true);
	return (false);
}

int	prec(t_token_type type)
{
	if (type == T_OR)
		return (0);
	if (type == T_AND)
		return (1);
	return (2);
}

bool	ft_get_io_list(t_io_node **io_list)
{
	t_token_type		redir_type;
	t_io_node	*tmp_io_node;

	if (g_minishell.parse_err.type)
		return (false);
	while (g_minishell.curr_token && is_redir(g_minishell.curr_token->type))
	{
		redir_type = g_minishell.curr_token->type;
		get_next_token();
		if (!g_minishell.curr_token)
			return (ft_set_parse_err(E_SYNTAX), false);
		if (g_minishell.curr_token->type != T_IDENTIFIER)
			return (ft_set_parse_err(E_SYNTAX), false);
		tmp_io_node = ft_new_io_node(redir_type, g_minishell.curr_token->value);
		if (!tmp_io_node)
			return (ft_set_parse_err(E_MEM), false);
		ft_append_io_node(io_list, tmp_io_node);
		get_next_token();
	}
	return (true);
}

bool	ft_join_args(char **args)
{
	char	*to_free;

	if (g_minishell.parse_err.type)
		return (false);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (ft_set_parse_err(E_MEM), false);
	while (g_minishell.curr_token && g_minishell.curr_token -> type == T_IDENTIFIER)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, g_minishell.curr_token -> value, ' ');
		if (!*args)
			return (free(*args), ft_set_parse_err(E_MEM), false);
		free(to_free);
		get_next_token();
	}
	return (true);
}

t_node	*get_simple_cmd()
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	node = ft_new_node(T_CMD);
	if (!node)
		return (ft_set_parse_err(E_MEM), NULL);
	while (g_minishell.curr_token
		&& (g_minishell.curr_token->type == T_IDENTIFIER || is_redir(g_minishell.curr_token->type)))
	{
		if (g_minishell.curr_token->type == T_IDENTIFIER)
		{
			if (!ft_join_args(&(node -> args)))
				return (NULL);
		}
		else if (is_redir(g_minishell.curr_token->type))
		{
			if (!ft_get_io_list(&(node->io_list)))
				return (NULL);
		}
	}
	return (node);
}

t_node	*term()
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	if (is_binop(g_minishell.curr_token->type))
		return (ft_set_parse_err(E_SYNTAX), NULL);
	else if (g_minishell.curr_token->type == T_O_PARENT)
	{
		get_next_token();
		node = expression(0);
		if (!g_minishell.curr_token || g_minishell.curr_token->type != T_C_PARENT)
			return (ft_set_parse_err(E_SYNTAX), NULL);
		get_next_token();
		return (node);
	}
	else
		return get_simple_cmd();
}

t_node	*combine(t_token_type op, t_node *left, t_node *right)
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	node = ft_new_node(op);
	if (!node)
		return (ft_set_parse_err(E_MEM), NULL);
	node -> left = left;
	node -> right = right;
	return (node);
}

t_node	*expression(int min_prec)
{
	t_node	*left;
	t_node	*right;
	int		n_prec;
	t_token_type	op;

	if (g_minishell.parse_err.type)
		return (NULL);
	left = term();
	if (!left)
		return (NULL);
	while (g_minishell.curr_token && is_binop(g_minishell.curr_token->type) && prec(g_minishell.curr_token->type) >= min_prec)
	{
		op = g_minishell.curr_token->type;
		get_next_token();
		if (!g_minishell.curr_token)
			return (ft_set_parse_err(E_SYNTAX), NULL);
		n_prec = prec(op) + 1;
		right = expression(n_prec);
		if (!right)
			return (NULL);
		left = combine(op, left, right);
		if (!left)
			return (NULL);
	}
	return (left);
}

t_node	*ft_parse()
{
	g_minishell.curr_token = g_minishell.tokens;
	return expression(0);
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

void	print_token(t_token *tokens)
{
	while (tokens)
	{
		printf("%s\n", types[tokens->type]);
		tokens = tokens -> next;
	}
}