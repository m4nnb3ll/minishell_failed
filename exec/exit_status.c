/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:49:57 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 18:56:28 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

void	exit_status(char *path)
{
	if (!path)
		g_minishell.exit_s = 127;
	else
		g_minishell.exit_s = 0;
}
