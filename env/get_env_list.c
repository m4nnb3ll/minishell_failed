/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:42:26 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 14:44:30 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	get_env_list(char **enviro)
{
<<<<<<< HEAD
=======
	// t_env	*list;
>>>>>>> upstream/main
	int		i;

	i = 0;
	g_minishell.list = NULL;
<<<<<<< HEAD
=======
	// list = g_minishell.list;
>>>>>>> upstream/main
	while (enviro[i])
	{
		add_node(new_node(get_key(enviro[i]), get_value(enviro[i])));
		i++;	
	}
}
