/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:42:22 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/03 15:44:31 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H


#include "tokenizer.h"//remove this later after setting minishell.h


typedef struct s_node
{
	t_type			type;
	char			*value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

t_node	*ft_new_node(char *value, t_type type);
void	ft_append_node(t_node **lst, t_node *new_node);
void	ft_clear_tree(t_node **lst);

#endif