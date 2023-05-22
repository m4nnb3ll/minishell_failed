/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:07:56 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/22 19:11:52 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

// T_CMD
// T_AND
// T_OR
// T_PIPE


void	exec()
{
	t_node	*tree;
	t_exec	exec;
	int	child;
	t_context	ctx;
	t_node	*tmp;
	int	status;
	int	i = 0;

	exec_init();
	ctx.fd[0] = 0;
	ctx.fd[1] = 1;
	g_minishell.index = 0;
	g_minishell.in_pipe = 0;
	ctx.fd_close = NULL;
	ctx.here_doc = NULL;
	tree = g_minishell.ast;
	tmp = g_minishell.ast;
	traverse_tree(tmp, &ctx);
	child = exec_node(tree, &ctx);
	close_parent_here_doc(&ctx);
	while (i < child)
	{
		wait(&status);
		i++;
	}
	if (WIFEXITED(status))
		g_minishell.exit_s = WEXITSTATUS(status);
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
