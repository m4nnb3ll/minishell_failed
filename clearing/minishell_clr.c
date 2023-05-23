/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:55:58 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 19:37:07 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_exec(void)
{
	if (g_minishell.exec.path)
	{
		free(g_minishell.exec.path);
		g_minishell.exec.path = NULL;
	}
	if (g_minishell.exec.args)
	{
		ft_free_char2(g_minishell.exec.args);
		g_minishell.exec.args = NULL;
	}
}

void	ft_clear_minishell(void)
{
	env_clear(&g_minishell.env_list);
	free(g_minishell.line);
	if (g_minishell.ast)
		ft_clear_ast(&g_minishell.ast);
	ft_free_exec();
}
