/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:11:56 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 17:56:38 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 16:31:50 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	*buff;

	buff = NULL;
	buff = getcwd(buff, 0);
	if (buff)
		printf("%s\n", buff);
	else
	{
		printf("error\n");
		g_minishell.exit_s = 1;
	}
	g_minishell.exit_s = 0;
}
