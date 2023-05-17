/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:07:53 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/16 22:21:21 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_next_token(void)
{
	g_minishell.curr_token = g_minishell.curr_token -> next;
}

bool	ft_curr_token_is_binop(void)
{
	t_token_type	type;

	if (!g_minishell.curr_token)
		return (false);
	type = g_minishell.curr_token->type;
	if (type == T_PIPE || type == T_AND || type == T_OR)
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

int	ft_curr_token_prec(void)
{
	return (prec(g_minishell.curr_token->type));
}
