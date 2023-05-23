/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:40:27 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 20:03:04 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_value(void)
{
	t_env	*list;

	list = g_minishell.env_list;
	while (list)
	{
		printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
}
