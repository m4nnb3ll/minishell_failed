/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:13:52 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 17:58:22 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin_child(void)
{
	if (ft_strcmp(g_minishell.exec.args[0], "echo") == 0)
		echo(g_minishell.exec.args);
	if (ft_strcmp(g_minishell.exec.args[0], "cd") == 0)
		cd(g_minishell.exec.args[1]);
	else if (ft_strcmp(g_minishell.exec.args[0], "exit") == 0)
		ft_exit(g_minishell.exec.args);
	else if (ft_strcmp(g_minishell.exec.args[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(g_minishell.exec.args[0], "export") == 0)
		export(g_minishell.exec.args);
	else if (ft_strcmp(g_minishell.exec.args[0], "unset") == 0)
		unset(g_minishell.exec.args);
	else if (ft_strcmp(g_minishell.exec.args[0], "env") == 0)
		env();
}

void	here_doc_content(t_context *ctx)
{
	int		i;
	t_fd	*close_pipe;

	close_pipe = ctx->here_doc;
	i = 0;
	while (1)
	{
		if (i == g_minishell.index)
			break ;
		close_pipe = close_pipe->next;
		i++;
	}
	ctx->fd[0] = close_pipe->content;
	g_minishell.index++;
}

void	exec_child_helper(t_context **ctx, int redirect)
{
	dup2((*ctx)->fd[0], 0);
	dup2((*ctx)->fd[1], 1);
	close_child_fds((*ctx));
	if (is_builtin_child() == 1)
	{
		exec_builtin_child();
		exit(0);
	}
	if (redirect == 0)
		exit(1);
	if (execve(g_minishell.exec.path, g_minishell.exec.args, NULL) == -1)
	{
		free_twod_array(g_minishell.exec.args);
		free(g_minishell.exec.path);
		exit(EXIT_FAILURE);
	}
}

int	exec_child(t_node *tree, t_context *ctx)
{
	int	redirect;
	int	pid;

	g_minishell.exec.args = expander(tree->args);
	if (g_minishell.exec.args)
		g_minishell.exec.path = path_getter(g_minishell.exec.args[0]);
	redirect = check_redirection(tree->io_list, ctx);
	exit_status();
	if (g_minishell.in_pipe == 0)
	{
		if (is_builtin_child() == 1)
		{
			exec_builtin_child();
			return (0);
		}
	}
	pid = fork();
	if (pid == 0)
		exec_child_helper(&ctx, redirect);
	return (1);
}
