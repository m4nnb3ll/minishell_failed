/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:46:05 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/26 18:34:05 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	exec_builtin_parent()
{
	g_minishell.exit_s = 0;
	if (ft_strcmp(g_minishell.exec.args[0], "cd") == 0)
		cd(g_minishell.exec.args[1]);
	else if (ft_strcmp(g_minishell.exec.args[0], "exit") == 0)
		ft_exit(g_minishell.exec.args);
	else if (ft_strcmp(g_minishell.exec.args[0], "export") == 0)
		export(g_minishell.exec.args);
	else if (ft_strcmp(g_minishell.exec.args[0], "unset") == 0)
		unset(g_minishell.exec.args);
}

int	is_builtin_parent()
{
	if (!*g_minishell.exec.args)
		return (0);
	else if (ft_strcmp(g_minishell.exec.args[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "export") == 0)
		return (1);
	else if (ft_strcmp(g_minishell.exec.args[0], "unset") == 0)
		return (1);
	return (0);
}

void	exec_builtin_child()
{
	g_minishell.exit_s = 0;
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
