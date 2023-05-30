/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:43:46 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/28 15:53:30 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	check_exec(char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, X_OK) == -1)
		{
			g_minishell.error_code = PERMISSION_DENIED_PROGRAM;
			return ;
		}
		g_minishell.error_code = SUCCESS;
		return ;
	}
	g_minishell.error_code = CMD_NOT_FOUND;
}

void	check_program(char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, X_OK) == -1)
		{
			g_minishell.error_code = PERMISSION_DENIED_PROGRAM;
			return ;
		}
		g_minishell.error_code = SUCCESS;
		return ;
	}
	g_minishell.error_code = NO_SUCH_FILE_PROGRAM;
}

void	check_read(char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, R_OK) == -1)
		{
			g_minishell.error_code = PERMISSION_DENIED_FILE;
			return ;
		}
		g_minishell.error_code = SUCCESS;
		return ;
	}
	g_minishell.error_code = NO_SUCH_FILE_FILE;
}

void	check_write(char *file)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, W_OK) == -1)
		{
			g_minishell.error_code = PERMISSION_DENIED_FILE;
			return ;
		}
		g_minishell.error_code = SUCCESS;
		return ;
	}
	g_minishell.error_code = NO_SUCH_FILE_FILE;
}
