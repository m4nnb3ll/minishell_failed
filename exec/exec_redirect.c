/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:32:29 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 19:39:30 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

int	out(char *file, t_context *ctx)
{
	int		fd;
	char	**expanded;

	expanded = expander(file);
	if (!expanded[0])
	{
		error_msg(file, "ambiguous redirect", 1);
		g_minishell.exit_s = 1;
		return (0);
	}
	else
	{
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			printf("out_error\n");
		ctx->fd[1] = fd;
		return (1);
	}
	return (0);
}

int	in(char *file, t_context *ctx)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error_msg(file, "No such file or directory", 1);
		g_minishell.exit_s = 1;
		return (0);
	}
	ctx->fd[0] = fd;
	return (1);
}

int	append(char *file, t_context *ctx)
{
	int	fd;
	char	**expanded;

	expanded = expander(file);
	if (!expanded[0])
	{
		error_msg(file, "ambiguous redirect", 1);
		g_minishell.exit_s = 1;
		return (0);
	}
	else
	{
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			printf("app_error\n");
		ctx->fd[1] = fd;
	}
	return (1);
}

int	here_doc(char *delimiter, t_context *ctx)
{
	char	*red;
	int		p[2];

	pipe(p);
	while (1)
	{
		red = readline("> ");	
		if (ft_strcmp(red, delimiter) == 0)
			break ;
		ft_putstr_fd(red, p[1]);
		ft_putstr_fd("\n", p[1]);
	}
	add_list(&(ctx->here_doc), new_list(p[0]));
	close(p[1]);
	return (1);
}
