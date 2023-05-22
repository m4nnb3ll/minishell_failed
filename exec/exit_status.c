/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:49:57 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/22 13:06:15 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	exit_status()
{
	if (!g_minishell.exec.path && (is_builtin_child() == 0))
		g_minishell.exit_s = 127;
	else
		g_minishell.exit_s = 0;
}
