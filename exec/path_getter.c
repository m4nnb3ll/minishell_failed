/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:45 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/16 12:43:16 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*char	*cmd_access(char *result, char *cmd)
{
	char	*err_msg;

	if (access(result, X_OK))
	{
		ft_putstr_fd(err_msg, 2);
		exit(126);
		return (0);
	}
	else
		return (result);
	return (0);
}*/

char	*check_cmd(char *cmd, char *path)
{
	int		i;
	char	**splited_path;
	char	*result;
	char	*err_msg;

	i = 0;
	splited_path = ft_split(path, ':');
	while (splited_path && splited_path[i])
	{
		result = ft_strjoin(splited_path[i], "/");
		result = ft_strjoin(result, cmd);
		if (access(result, F_OK) == 0)
		{
			//result = cmd_access(result, cmd);
			return (result);
		}
		i++;
	}
	return (0);
}

char	*check_path(char *cmd, char *env)
{
	char	*result;

	result = check_cmd(cmd, env);
	return (result);
}

char	*path_getter(char *cmd)
{
	char	*cmd_path;
	t_env	*tmp;
	char	*env;

	if (!cmd)
		return (0);
	tmp = get_node("PATH");
	if (!tmp)
		return (0);
	cmd_path = check_path(cmd, tmp->value);
	return (cmd_path);
}
