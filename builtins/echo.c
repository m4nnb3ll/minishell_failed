/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:01:26 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/22 15:38:28 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	check_flag(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	else
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')	
			return (1);
		i++;
	}
	return (0);
}

void	echo(char **cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (cmd && cmd[i])
	{
		if (check_flag(cmd[i]) == 1)
			break ;
		flag = 1;
		i++;
	}
	while (cmd && cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if ((cmd + i + 1) && cmd [i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", 1);
}
