/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:46:02 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/19 15:52:57 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	add_node(t_env *new)
{
	t_env	*list;

	if (g_minishell.list == NULL)
	{
		g_minishell.list = new;
		return ;	
	}
	list = g_minishell.list;
	while (list->next)
		list = list->next;
	list->next = new;
}
