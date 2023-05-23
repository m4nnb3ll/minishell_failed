/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:45 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 14:45:08 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_cmd(char *cmd, char *path)
{
	int		i;
	char	**splited_path;
	char	*result;
	// char	*err_msg;

	i = 0;
	splited_path = ft_split(path, ':');
	while (splited_path && splited_path[i])
	{
		result = ft_strjoin(splited_path[i], "/");
		result = ft_strjoin(result, cmd);
		if (access(result, F_OK) == 0)
		{
			if (access(result, X_OK) == 1)
			{
				error_msg(cmd, "permission denied", 126);
				return (0);	
			}
			return (result);
		}
		i++;
	}
	return (0);
}

int	check_existence(char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 1)
		{
			error_msg(cmd, "permission denied", 126);
			return (2);
		}
		return (1);
	}
	return (0);
}

char	*check_path(char *cmd, char *env)
{
	char	*result;

	check_existence(cmd);
	result = check_cmd(cmd, env);
	return (result);
}

char	*path_getter(char *cmd)
{
	char	*cmd_path;
	t_env	*tmp;
	// char	*env;
	int	exist;

	if (!cmd)
		return (0);
	exist = check_existence(cmd);
	if (exist == 1)
		return (cmd);
	else if (exist == 2)
		return (0);
	tmp = get_node("PATH");
	if (!tmp)
		return (0);
	cmd_path = check_path(cmd, tmp->value);
	if (!cmd)
		error_msg(g_minishell.exec.args[0], "command not found", 127);
	return (cmd_path);
}
