/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:40:53 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/29 15:26:24 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 18:09:29 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	traverse_tree(t_node *tree, t_context *ctx)
{
	if (!tree)
		return ;
	if (tree->type == N_PIPE)
		traverse_pipe(tree, ctx);
	else if (tree->type == N_CMD)
		traverse_child(tree, ctx);
<<<<<<< HEAD
	else if (tree->type == N_OR)
		traverse_or(tree, ctx);
	else if (tree->type == N_AND)
		traverse_and(tree, ctx);
	else
		printf("traverse_error\n");
=======
>>>>>>> upstream/main
}

void	traverse_pipe(t_node *tree, t_context *ctx)
{
	traverse_tree(tree->left, ctx);
	traverse_tree(tree->right, ctx);
}

void	traverse_child(t_node *tree, t_context *ctx)
{
<<<<<<< HEAD
	t_io_node	*io = tree->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
			here_doc(io->value, ctx);
=======
	int			i;
	t_io_node	*io;

	io = tree->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
			i = here_doc(io->value, ctx);
		if (i == 0)
			break ;
>>>>>>> upstream/main
		io = io->next;
	}
}

void	traverse_and(t_node *tree, t_context *ctx)
{
	traverse_tree(tree->left, ctx);
	traverse_tree(tree->right, ctx);
}

void	traverse_or(t_node *tree, t_context *ctx)
{
	traverse_tree(tree->left, ctx);
	traverse_tree(tree->right, ctx);
}
