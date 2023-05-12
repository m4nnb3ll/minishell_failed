/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:42:22 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/12 00:05:52 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H


#include "tokenizer.h"//remove this later after setting minishell.h

// typedef struct s_op
// {
// 	t_type	type;
// 	int		prec;
// }	t_op;

typedef struct s_node
{
	t_type			type;
	char			*value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

t_node	*ft_new_node(t_type type, char *value);
void	ft_append_node(t_node **lst, t_node *new_node);
void	ft_clear_tree(t_node **lst);

#endif