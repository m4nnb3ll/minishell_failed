/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:42:26 by oakerkao          #+#    #+#             */
/*   Updated: 2023/04/24 11:46:48 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	get_env_list(char **enviro)
{
	t_env	*list;
	int		i;

	i = 0;
	g_manager.list = NULL;
	list = g_manager.list;
	while (enviro[i])
	{
		add_node(new_node(get_key(enviro[i]), get_value(enviro[i])));
		i++;	
	}
}
