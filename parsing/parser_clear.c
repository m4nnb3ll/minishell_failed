/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:47:04 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/16 17:47:04 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_clear_io_list(t_io_node **lst)
{
    t_io_node    *curr_node;
    t_io_node    *next;

    curr_node = *lst;
    if (!curr_node)
        return ;
    while (curr_node)
    {
        free(curr_node->value);
        next = curr_node->next;
        free(curr_node);
        curr_node = next;
    }
    *lst = NULL;
}

// void	ft_clear_cmd_node(t_cmd_node *node)
// {
//     if (!node)
// 		return ;
//     ft_free_char2(node -> args);
//     ft_clear_io_list(&(node -> io_list));
// }

// void	ft_recursive_clear_tree(t_node *node)
// {
//     if (!node)
//         return ;
//     if (node -> type == T_CMD)
//         ft_clear_cmd_node((t_cmd_node *)node);
//     else
// 	{
// 		if (node->left)
// 			ft_recursive_clear_tree(node->left);
// 		if (node->right)
// 			ft_recursive_clear_tree(node->right);
// 	}
// 	free(node);
// }

// void	ft_clear_tree(void **tree)
// {
// 	ft_recursive_clear_tree(*tree);
// 	*tree = NULL;
// }
