/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:32:25 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/22 15:00:16 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
