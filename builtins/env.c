/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:29:54 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 17:58:43 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 19:08:14 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(void)
{
	t_env	*list;

	list = g_minishell.env_list;
	while (list)
	{
		if (list->value != NULL)
			printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	g_minishell.exit_s = 0;
}
