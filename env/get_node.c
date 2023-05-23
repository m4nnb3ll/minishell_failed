/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:31:27 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 15:57:01 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*get_node(char *key)
{
	t_env	*list;

	if (!key)
		return (0);
	list = g_minishell.list;
	while (list)
	{
		if (ft_strcmp(key, list->key) == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
