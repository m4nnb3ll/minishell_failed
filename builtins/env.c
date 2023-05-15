/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:29:54 by oakerkao          #+#    #+#             */
/*   Updated: 2023/04/24 13:10:06 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	env(void)
{
	t_env	*list;

	list = g_manager.list;
	while (list)
	{
		printf("%s=%s\n", list->key, list->value);	
		list = list->next;
	}
}
