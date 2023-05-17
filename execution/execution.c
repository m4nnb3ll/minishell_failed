/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:53:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/16 21:46:24 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	For now the function returns the exec status of each expression
*/

int	ft_exec_ast(t_node	*ast)
{
	int	tmp;

	if (node -> type == T_PIPE )
		return exec_pipe(ft_exec_ast(node->left), ft_exec_ast(node->right));
	else if (node -> type == &&)
	{
		tmp = ft_exec_ast(node->left);
		if (tmp)
			tmp = (ft_exec_ast(node->right));
		return (tmp);
	}
	else if (node -> type == ||)
	{
		tmp = ft_exec_ast(node->left);
		if (!tmp)
			tmp = (ft_exec_ast(node->right));
		return (tmp);
	}
	else
		return exec_cmd(node);
}
