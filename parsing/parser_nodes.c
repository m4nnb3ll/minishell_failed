/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:42:23 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/14 22:50:21 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*ft_new_node(t_type type)
{
    t_node    *new_node;

    new_node = (t_node *)ft_calloc(1, sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->type = type;
    return (new_node);
}

t_io_node	*ft_new_io_node(t_type type, char *value)
{
    t_io_node    *new_node;

    new_node = (t_io_node *)ft_calloc(1, sizeof(t_io_node));
    if (!new_node)
        return (NULL);
    new_node->type = type;
    new_node->value = value;
    return (new_node);
}

void	ft_append_io_node(t_io_node **lst, t_io_node *new)
{
	t_io_node	*curr_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr_node = *lst;
	while (curr_node && curr_node -> next)
		curr_node = curr_node -> next;
	curr_node -> next = new;
}
