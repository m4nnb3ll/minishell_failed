/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:13:52 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/22 10:02:17 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	exec_builtin(char **args)
{
	if (ft_strcmp(args[0], "echo") == 0)
		echo(args);
	if (ft_strcmp(args[0], "cd") == 0)
		cd(args[1]);
	else if (ft_strcmp(args[0], "exit") == 0)
		ft_exit(args);
	else if (ft_strcmp(args[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(args[0], "export") == 0)
		export(args);
	else if (ft_strcmp(args[0], "unset") == 0)
		unset(args);
	else if (ft_strcmp(args[0], "env") == 0)
		env();
}

int	is_builtin(char **args)
{
	if (!*args)
		return (0);
	if (ft_strcmp(args[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(args[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(args[0], "export") == 0)
		return (1);
	else if (ft_strcmp(args[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(args[0], "env") == 0)
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
	char	*path;
	char	**args;
	int		status;
	int	redirect;
	int	pid;

	path = NULL;
	args = expander(tree->args);
	if (args)
		path = path_getter(args[0]);
	redirect = check_redirection(tree->io_list, ctx);
	if (redirect == 0)
		return (0);
	if (redirect != 0)
		exit_status(path);
	//if (path && (is_builtin(args) == 0))	
	//{
		pid = fork();
		if (pid == 0)
		{
			dup2(ctx->fd[0], 0);
			dup2(ctx->fd[1], 1);
			close_child_fds(ctx);
			if (is_builtin(args) == 1)
			{
				exec_builtin(args);
				exit(0);
			}
			if (execve(path, args, NULL) == -1)
			{
				if (!path)
					error_msg(args[0], "command not found", 127);
				exit(1);
			}
		}
	//}
	return (1);
}
