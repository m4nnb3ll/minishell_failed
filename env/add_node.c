/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:46:02 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 16:37:49 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
