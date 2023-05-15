/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:28:41 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/15 15:38:02 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tree(t_node *node);

int	main()
{
	minishell.tokens = ft_tokenize();
	if (minishell.tokens)
		minishell.tree = ft_parse();
	print_tree(minishell.tree);
}