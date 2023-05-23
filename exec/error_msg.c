/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:22:19 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 16:01:30 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	error_msg(char *file, char *err_msg, int exit_code)
{
	char	*final;
	char	*to_free;

	to_free = ft_strjoin("minishell", ": ");
	final = ft_strjoin(to_free, file);
	free(to_free);
	to_free = ft_strjoin(final, ": ");
	free(final);
	final = ft_strjoin(to_free, err_msg);
	ft_putstr_fd(final, 2);
	ft_putstr_fd("\n", 2);
	free(final);
	if (exit_code == 127)
		g_minishell.exit_s = 127;
	else if (exit_code == 1)
		g_minishell.exit_s = 1;

}
