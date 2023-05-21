/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:10:44 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/15 19:47:34 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**str_to_twod(char *str)
{
	int		i;
	char	**arr;

	i = 0;
	arr = malloc(2 * sizeof(char *));
	arr[i] = ft_strdup(str);
	arr[++i] = NULL;
	return (arr);
}

char	**cmd_getter(char *arg)
{
	char	**cmd;

	cmd = NULL;
	cmd = ft_split(arg, ' ');
	return (cmd);
}
