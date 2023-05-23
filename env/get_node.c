/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:31:27 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 19:08:14 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_node(char *key)
{
	t_env	*list;

	if (!key)
		return (0);
	list = g_minishell.env_list;
	while (list)
	{
		if (ft_strcmp(key, list->key) == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
