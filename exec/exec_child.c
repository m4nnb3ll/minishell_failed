/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:13:52 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 14:45:49 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	exec_builtin_child()
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

int	is_builtin_child()
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

int	exec_child(t_node *tree, t_context *ctx)
{
	// int	status;
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
	{
		dup2(ctx->fd[0], 0);
		dup2(ctx->fd[1], 1);
		close_child_fds(ctx);
		if (is_builtin_child() == 1)
		{
			exec_builtin_child();
			exit(0);
		}
		if (redirect == 0)
			exit(1);
		if (execve(g_minishell.exec.path, g_minishell.exec.args, NULL) == -1)
		{
			//exit_child();
			//exit the true exit status even if it doesn't affect the parent 
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
