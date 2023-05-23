/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:57:41 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 17:58:08 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_child(void)
{
	if (!*g_minishell.exec.args)
		return (0);
	if (ft_strcmp(g_minishell.exec.args[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "export") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "env") == 0)
		return (1);
	return (0);
}

int	check_redirection(t_io_node *io, t_context *ctx)
{
	int	i;

	i = 1;
	while (io)
	{
		if (io->type == IO_OUT)
			i = out(io->value, ctx);
		else if (io->type == IO_IN)
			i = in(io->value, ctx);
		else if (io->type == IO_APPEND)
			i = append(io->value, ctx);
		else if (io->type == IO_HEREDOC)
			here_doc_content(ctx);
		if (i == 0)
			return (0);
		io = io->next;
	}
	return (1);
}
