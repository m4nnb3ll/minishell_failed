/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:07:56 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 15:58:40 by oakerkao         ###   ########.fr       */
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
	t_node	*tmp;
	t_context	ctx;
	t_wait		wait_var;

	exec_init(&ctx, &wait_var);
	tree = g_minishell.ast;
	tmp = g_minishell.ast;
	traverse_tree(tmp, &ctx);
	wait_var.child = exec_node(tree, &ctx);
	close_parent_here_doc(&ctx);
	while (wait_var.i < wait_var.child)
	{
		wait(&wait_var.status);
		wait_var.i++;
	}
	if (WIFEXITED(wait_var.status))
		g_minishell.exit_s = WEXITSTATUS(wait_var.status);
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
