/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:19:12 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 17:51:08 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 16:31:47 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(void)
{
	t_env	*current;
	char	*str;

	str = getcwd(NULL, 0);
	current = get_node("PWD");
	if (str && current)
		current->value = str;
}

void	change_old_pwd(void)
{
	t_env	*old;
	t_env	*current;

	old = get_node("OLDPWD");
	current = get_node("PWD");
	if (old && current)
		old->value = current->value;
}

void	change_to_home(void)
{
	t_env	*home;
	t_env	*current;

	change_old_pwd();
	home = get_node("HOME");
	current = get_node("PWD");
	if (home && current)
	{
		current->value = home->value;
		chdir(home->value);
		g_minishell.exit_s = 0;
	}
	else
	{
		printf("minishell: cd: HOME not set\n");
		g_minishell.exit_s = 1;
	}
}

void	cd(char *path)
{
	if (!path)
	{
		change_to_home();
		return ;
	}
	if (chdir(path) == -1)
	{
		printf("minishell: %s: No such file or directory\n", path);
		g_minishell.exit_s = 1;
		return ;
	}
	change_old_pwd();
	change_pwd();
	g_minishell.exit_s = 0;
}
