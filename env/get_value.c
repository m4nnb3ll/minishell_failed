/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:32:25 by oakerkao          #+#    #+#             */
/*   Updated: 2023/04/24 11:37:43 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_value(char *str)
{
	int		len;
	char	*new;

	if (ft_strchr(str, '=') == NULL)
		len = ft_strlen(str) + 1;
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
