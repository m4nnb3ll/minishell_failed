/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:56:37 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 17:57:11 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 19:08:14 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_node(char *key)
{
	t_env	*current;
	t_env	*prev;

	prev = NULL;
	current = g_minishell.env_list;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				g_minishell.env_list = current->next;
			free(current);
			break ;
		}
		prev = current;
		current = current->next;
	}
}

void	unset(char **args)
{
	int	i;

	i = 1;
	if (!*args)
		return ;
	while (args[i])
	{
<<<<<<< HEAD
		if(check_key(args[i]) == 0)
=======
		if (check_key(args[i]) == 0)
		{
			printf("here\n");
>>>>>>> upstream/main
			return ;
		else if (ft_strchr(args[i], '='))
			return ;
		else
			remove_node(get_key(args[i]));
		i++;
	}
	g_minishell.exit_s = 0;
}
