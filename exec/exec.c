/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:07:56 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 16:20:17 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

// T_CMD
// T_AND
// T_OR
// T_PIPE


void	exec()
{
	t_node	*tree;
	int	status;
	int	child;
	t_context	ctx;
	t_node	*tmp;
	int	i = 0;

	ctx.fd[0] = 0;
	ctx.fd[1] = 1;
	g_minishell.index = 0;
	ctx.fd_close = NULL;
	ctx.here_doc = NULL;
	tree = g_minishell.ast;
	tmp = g_minishell.ast;
	traverse_tree(tmp, &ctx);
	child = exec_node(tree, &ctx);
	close_parent_here_doc(&ctx);
	while (i < child)
	{
		wait(NULL);
		i++;
	}
	if (WIFEXITED(status))
		g_minishell.exit_s = WEXITSTATUS(status);
	//printf("%d\n", g_minishell.exit_s);
	//exit(g_minishell.exit_s);
}

int	exec_node(t_node *tree, t_context *ctx)
{
	if (!tree)
		return (0);
	if (tree->type == N_PIPE)
		return (exec_pipe(tree, ctx));
	else if (tree->type == N_CMD)
		return (exec_child(tree, ctx));
	else if (tree->type == N_OR) 
		return (exec_or(tree, ctx));
	else if (tree->type == N_AND)
		return (exec_and(tree, ctx));
	else
		printf("nerror\n");
	return (0);
}

int	exec_and(t_node *tree, t_context *ctx)
{
	int	i;

	i = 0;
	i += exec_node(tree->left, ctx);
	if (g_minishell.exit_s == 0)
		i += exec_node(tree->right, ctx);
	return (i);
}

int	exec_or(t_node *tree, t_context *ctx)
{
	int	i;

	i = 0;
	i += exec_node(tree->left, ctx);
	if (g_minishell.exit_s != 0)
		i += exec_node(tree->right, ctx);
	return (i);
}
