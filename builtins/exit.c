/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:41:56 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 15:35:20 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	exit_error_msg(char *str)
{
	char	*error_msg;

	error_msg = ft_strjoin("bash: exit: ", str);
	error_msg = ft_strjoin(error_msg, ": numeric argument required\n");
	ft_putstr_fd(error_msg, 2);
}

int	check_long(unsigned long long res, int sign)
{
	if (res > 9223372036854775807 && sign == 1)
		return (0);
	else if (res > 9223372036854775808UL && sign == -1)
		return (0);
	return (1);
}

int	is_valid(char *str, int sign)
{
	int					i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (str[i])	
	{
		if (res > res * 10 + (str[i] - 48))	
			return (0);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (check_long(res ,sign));
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))	
			return (0);
		i++;
	}
	return (1);
}

int	check_exit_arg(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (is_number(str + i) == 0 || is_valid(str + i, sign) == 0)
	{
		exit_error_msg(str);
		exit(255);
	}
	return (ft_atoi(str));
}

void	ft_exit(char **args)
{
	int	exit_value;

	exit_value = 0;
	printf("exit\n");
	if (args[1])
	{
		if (args[2])
		{
			error_msg("exit", "too many arguments", 1);
			exit(1);
		}
		exit_value = check_exit_arg(args[1]);
	}
	exit(exit_value);
}
