/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:55:17 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/17 01:31:09 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*term(void)
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	if (ft_curr_token_is_binop() || g_minishell.curr_token->type == T_C_PARENT)
		return (ft_set_parse_err(E_SYNTAX), NULL);
	else if (g_minishell.curr_token->type == T_O_PARENT)
	{
		get_next_token();
		node = expression(0);
		if (!node)
			return (ft_set_parse_err(E_MEM), NULL);
		if (!g_minishell.curr_token
			|| g_minishell.curr_token->type != T_C_PARENT)
			return (ft_set_parse_err(E_SYNTAX), node);
		get_next_token();
		return (node);
	}
	else
		return (get_simple_cmd());
}

t_node	*combine(t_token_type op, t_node *left, t_node *right)
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	node = ft_new_node(ft_get_node_type(op));
	if (!node)
		return (ft_set_parse_err(E_MEM), NULL);
	node -> left = left;
	node -> right = right;
	return (node);
}

t_node	*expression(int min_prec)
{
	t_node			*left;
	t_node			*right;
	int				n_prec;
	t_token_type	op;

	if (g_minishell.parse_err.type || !g_minishell.curr_token)
		return (NULL);
	left = term();
	if (!left)
		return (NULL);
	while (ft_curr_token_is_binop() && ft_curr_token_prec() >= min_prec)
	{
		op = g_minishell.curr_token->type;
		get_next_token();
		if (!g_minishell.curr_token)
			return (ft_set_parse_err(E_SYNTAX), left);
		n_prec = prec(op) + 1;
		right = expression(n_prec);
		if (!right)
			return (left);
		left = combine(op, left, right);
		if (!left)
			return (ft_clear_ast(&left), ft_clear_ast(&right), NULL);
	}
	return (left);
}

t_node	*ft_parse(void)
{
	t_node	*ast;

	g_minishell.curr_token = g_minishell.tokens;
	ast = expression(0);
	if (g_minishell.curr_token)
		return (ft_set_parse_err(E_SYNTAX), ast);
	return (ast);
}
