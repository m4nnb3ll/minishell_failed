/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:50:17 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/17 01:56:08 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_parse_err(t_parse_err_type type)
{
	g_minishell.parse_err.type = type;
}

void	ft_handle_parse_err(void)
{
	t_parse_err_type	type;
	t_token_type		token_type;
	char				**types;

	types = (char *[]){"T_IDENTIFIER",
		"<", ">", "<<", ">>", "|", "(", ")", "&&", "||", "newline"};
	type = g_minishell.parse_err.type;
	if (type)
	{
		ft_clear_ast(&g_minishell.ast);
		if (type == E_SYNTAX)
		{
			if (!g_minishell.curr_token)
				token_type = T_NL;
			else
				token_type = g_minishell.curr_token->type;
			ft_putstr_fd("msh: syntax error near unexpected token `", 2);
			ft_putstr_fd(types[token_type], 2);
			ft_putstr_fd("'\n", 2);
		}
		ft_bzero(&g_minishell.parse_err, sizeof(t_parse_err));
	}
}
