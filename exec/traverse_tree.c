/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:40:53 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 21:26:42 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	traverse_tree(t_node *tree, t_context *ctx)
{
	if (!tree)
		return ;
	if (tree->type == N_PIPE)
		traverse_pipe(tree, ctx);
	else if (tree->type == N_CMD)
		traverse_child(tree, ctx);
	/*else if (tree->type == N_OR)
		traverse_or(tree, ctx);
	else if (tree->type == N_AND)
		traverse_and(tree, ctx);
	else
		printf("nerror\n");*/
}

void	traverse_pipe(t_node *tree, t_context *ctx)
{
	//left_node
	traverse_tree(tree->left, ctx);
	
	// right_node
	traverse_tree(tree->right, ctx);
}

void	traverse_child(t_node *tree, t_context *ctx)
{
	int	i;
	t_io_node	*io = tree->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
			i = here_doc(io->value, ctx);
		if (i == 0)
			break ;
		io = io->next;	
	}
}

void	traverse_and(t_node *tree, t_context *ctx)
{
	exec_node(tree->left, ctx);
	if (g_minishell.exit_s == 0)
		exec_node(tree->right, ctx);
}

void	traverse_or(t_node *tree, t_context *ctx)
{
	exec_node(tree->left, ctx);
	if (g_minishell.exit_s != 0)
		exec_node(tree->right, ctx);
}
