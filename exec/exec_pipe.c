/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:38:01 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 17:31:46 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 18:06:27 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_pipe(t_node *tree, t_context *ctx)
{
	int			p[2];
	t_context	lctx;
	t_context	rctx;
<<<<<<< HEAD
	t_node	*ln;
	t_node	*rn;
	int		i;
=======
	int			i;
>>>>>>> upstream/main

	i = 0;
	g_minishell.in_pipe = 1;
	lctx = *ctx;
	rctx = *ctx;
<<<<<<< HEAD
	if (pipe(p) == -1)
		return (0);
	// left_child 
=======
	pipe(p);
	g_minishell.in_pipe = 1;
>>>>>>> upstream/main
	lctx.fd[1] = p[1];
	add_list(&(lctx.fd_close), new_list(p[0]));
	add_list(&(lctx.fd_close), new_list(p[1]));
	i += exec_node(tree->left, &lctx);
	rctx.fd[0] = p[0];
	add_list(&(rctx.fd_close), new_list(p[0]));
	add_list(&(rctx.fd_close), new_list(p[1]));
	i += exec_node(tree->right, &rctx);
	close(p[1]);
	close(p[0]);
	return (i);
}
