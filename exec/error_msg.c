/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:22:19 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 15:44:41 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 16:46:18 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
// error codes
// 0 ->success->0
// 1 ->command not found->127
// 21 ->no such file or directory "file"->1
// 22 ->no such file or directory "program"->127
// 31 ->permission denied for file->1
// 32 ->permission denied for program->126
// 4 ->ambiguous redirection->1
// 5 ->not a valid identifier->1
// 5 ->quit program ctrl+\->131

// problems i foudn
// i don't find space inside of doublequotes

void	error_script()
{
	if (g_minishell.error_code == CMD_NOT_FOUND)
		printf("minishell: %s: command not found\n", g_minishell.error_file);
	else if (g_minishell.error_code == NO_SUCH_FILE_FILE || g_minishell.error_code == NO_SUCH_FILE_PROGRAM)
		printf("minishell: %s: No such file or directory\n", g_minishell.error_file);
	else if (g_minishell.error_code == PERMISSION_DENIED_FILE || g_minishell.error_code == PERMISSION_DENIED_PROGRAM)
		printf("minishell: %s: permission denied\n", g_minishell.error_file);
	else if (g_minishell.error_code == AMBIGUOUS)
		printf("minishell: %s: ambiguous redirect\n", g_minishell.error_file);
}

void	error_msg()
{
	error_script();
	exit_status();
=======
void	error_msg(char *file, char *err_msg, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("\n", 2);
	if (exit_code == 127)
		g_minishell.exit_s = 127;
	else if (exit_code == 1)
		g_minishell.exit_s = 1;
>>>>>>> upstream/main
}
