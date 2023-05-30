/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:13:52 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/29 20:17:48 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 19:39:39 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
=======
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

>>>>>>> upstream/main
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

<<<<<<< HEAD
void check_redirection(t_io_node *io, t_context *ctx)
{
	char	**expanded;

	while (io)
	{
		g_minishell.in_redirect = 1;
		g_minishell.error_file = io->value;
		expanded = expander(io->value);
		if (io->type == IO_OUT)
			out(expanded[0], ctx);
		else if (io->type == IO_IN)
			in(expanded[0], ctx);
		else if (io->type == IO_APPEND)
			append(expanded[0], ctx);
		else if (io->type == IO_HEREDOC)
			here_doc_content(ctx);
		if (g_minishell.error_code != 0)
		{
			error_msg();
			free_twod_array(expanded);
			return ;
		}
		io = io->next;
		free_twod_array(expanded);
=======
void	exec_child_helper(t_context **ctx, int redirect)
{
	dup2((*ctx)->fd[0], 0);
	dup2((*ctx)->fd[1], 1);
	close_child_fds((*ctx));
	if (is_builtin_child() == 1)
	{
		exec_builtin_child();
		ft_clear_minishell();
		exit(0);
	}
	if (redirect == 0)
	{
		ft_clear_minishell();
		exit(1);
	}
	if (execve(g_minishell.exec.path, g_minishell.exec.args, NULL) == -1)
	{
		ft_clear_minishell();
		exit(EXIT_FAILURE);
>>>>>>> upstream/main
	}
}

int	exec_child(t_node *tree, t_context *ctx)
{
	int	pid;

	g_minishell.error_code = SUCCESS;
	g_minishell.exec.args = expander(tree->args);
	check_redirection(tree->io_list, ctx);
	if (g_minishell.error_code == SUCCESS)
	{
		if (is_builtin_parent() && g_minishell.in_pipe == 0)
		{
<<<<<<< HEAD
			exec_builtin_parent();
=======
			exec_builtin_child();
>>>>>>> upstream/main
			return (0);
		}
		else if (g_minishell.exec.args && is_builtin_child() == 0)
			g_minishell.exec.path = path_getter(g_minishell.exec.args[0]);
	}
	pid = fork();
	if (pid == 0)
<<<<<<< HEAD
	{
		exec_dup(ctx);
		if (g_minishell.error_code != 0)
		{
			free_ever();
			exit(g_minishell.exit_s);
		}
		else if (is_builtin_child())
		{
			exec_builtin_child();
			free_ever();
		}
		else if (g_minishell.exec.path)
		{
			if (execve(g_minishell.exec.path, g_minishell.exec.args, NULL) == -1)
				free_ever();
		}
		free_ever();
	}
	if (g_minishell.exec.args)
		free_twod_array(g_minishell.exec.args);
	if (g_minishell.exec.path)
		free(g_minishell.exec.path);
=======
		exec_child_helper(&ctx, redirect);
>>>>>>> upstream/main
	return (1);
}
