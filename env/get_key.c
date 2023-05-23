/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:47:28 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 16:37:58 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key(char *str)
{
	int		len;
	char	*new;

	if (ft_strchr(str, '=') == NULL)
		len = ft_strlen(str) + 1;
	else
	{
		new = ft_strchr(str, '=');
		len = new - str + 1;
	}
	new = malloc(len * sizeof(char));
	ft_strlcpy(new, str, len);
	return (new);
}
