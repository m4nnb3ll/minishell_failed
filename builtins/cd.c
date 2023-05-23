/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:19:12 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 14:46:08 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

<<<<<<< HEAD
void	change_pwd(void)
=======
void	change_pwd(/* char *path */)
>>>>>>> upstream/main
{
	t_env	*current;
	char	*str;

	str = getcwd(NULL, 0);
	current = get_node("PWD");
	current->value = str;
}

void	change_old_pwd()
{
	t_env	*old;
	t_env	*current;

	old = get_node("OLDPWD");
	current = get_node("PWD");
	old->value = current->value;
}

void	change_to_home()
{
	t_env	*home;
	t_env	*current;

	change_old_pwd();
	home = get_node("HOME");
	current = get_node("PWD");
	current->value = home->value;
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
		printf("error\n");
		return ;
	}
	change_old_pwd();
	change_pwd();
}
