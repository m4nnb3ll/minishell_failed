/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:40:27 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/18 12:52:57 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "env.h"

void	change_value()
{
	t_env	*list;

	list = g_minishell.list;
	while (list)
	{
		printf("%s=%s\n", list->key, list->value);	
		list = list->next;
	}
}

/*int main(int argc, char *argv[], char *env[])
{
	get_env_list(env);
	change_value();
}*/
