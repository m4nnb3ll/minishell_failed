/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .print_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:08:43 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/17 00:29:38 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NOTICE: MAKE SURE TO REMOVE THIS FILE ONCE YOU ARE DONE WITH THE MINISHELL!!!

#include "minishell.h"

bool	is_node_binop(t_node_type type)
{
	if (type == N_PIPE || type == N_AND || type == N_OR )
		return (true);
	return (false);
}

void	ft_print_io_list(t_io_node *io_list)
{
	while (io_list)
	{
		printf("%s ", io_list->value);
		io_list = io_list -> next;
	}
}

void	recursive_print_ast(t_node *node)
{
	char *types[] = {"|", "&&", "||", "CMD"};

	if (!node)
		return ;
	if (node -> type == N_CMD)
	{
		printf("%s ", node->args);
		printf("7BESS!!!\n");
		ft_print_io_list(node->io_list);
	}
	else
	{
		printf("(");
		if (node -> left)
			recursive_print_ast(node -> left);
		printf(" %s ", types[node->type]);
		if (node -> right)
			recursive_print_ast(node -> right);
		printf(")");
	}
}

void	print_ast(t_node *node)
{
	recursive_print_ast(node);
	printf("\n");
}