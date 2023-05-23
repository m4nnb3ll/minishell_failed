/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:34:40 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 10:37:51 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "env.h"

void	env_clear(t_env **env)
{
	t_env	*lst;

	lst = *env;
	if (*env == NULL)
		return ;
	while (lst)
	{
		lst = (*env)->next;
		free((*env)->key);
		free((*env)->value);
		free(*env);
		*env = lst;
	}
}
