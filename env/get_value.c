/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:32:25 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 16:37:59 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(char *str)
{
	int		len;
	char	*new;

	if (!str)
		return (0);
	if (ft_strchr(str, '=') == NULL)
		return (0);
	else
	{
		str = ft_strchr(str, '=');
		str++;
		len = ft_strlen(str) + 1;
	}
	new = malloc(len);
	ft_strlcpy(new, str, len);
	return (new);
}
