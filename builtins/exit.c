/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:41:56 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/29 15:38:51 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 19:38:59 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error_msg(char *str)
{
	char	*error_msg;

	error_msg = ft_strjoin("minishell: exit: ", str);
	error_msg = ft_strjoin(error_msg, ": numeric argument required\n");
	ft_putstr_fd(error_msg, 2);
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
		g_minishell.exit_s = 0;
		exit_error_msg(str);
<<<<<<< HEAD
		g_minishell.exit_s = 255;
		exit(g_minishell.exit_s);
=======
		ft_clear_minishell();
		exit(255);
>>>>>>> upstream/main
	}
	return (ft_atoi(str));
}

void	ft_exit(char **args)
{
	int	exit_value;

	exit_value = 0;
	if (args[1])
	{
		if (args[2])
		{
<<<<<<< HEAD
			g_minishell.exit_s = 1;
			printf("minishell: exit: too many arguments\n");
			g_minishell.exit_s = 1;
			exit(g_minishell.exit_s);
=======
			error_msg("exit", "too many arguments", 1);
			ft_clear_minishell();
			exit(1);
>>>>>>> upstream/main
		}
		exit_value = check_exit_arg(args[1]);
		g_minishell.exit_s = exit_value;
		exit(exit_value);
	}
<<<<<<< HEAD
	exit(0);
=======
	ft_clear_minishell();
	exit(exit_value);
>>>>>>> upstream/main
}
