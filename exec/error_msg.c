/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:22:19 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 21:25:54 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	error_msg(char *file, char *err_msg, int exit_code)
{
	char	*final;

	final = ft_strjoin("minishell", ": ");
	final = ft_strjoin(final, file);
	final = ft_strjoin(final, ": ");
	final = ft_strjoin(final, err_msg);
	if (final)
	{
		ft_putstr_fd(final, 2);
		ft_putstr_fd("\n", 2);
	}
	if (exit_code == 127)
		g_minishell.exit_s = 127;
	else if (exit_code == 1)
		g_minishell.exit_s = 1;

}
