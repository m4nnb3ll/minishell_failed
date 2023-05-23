/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:34:40 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 16:37:53 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
