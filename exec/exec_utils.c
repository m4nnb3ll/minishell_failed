/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:59:15 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 10:59:22 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

t_fd	*new_list(int content)
{
	t_fd	*head;

	head = (t_fd *)malloc(sizeof(t_fd));
	if (!head)
		return (0);
	head -> content = content;
	head -> next = NULL;
	return (head);
}

void	add_list(t_fd **lst, t_fd *new)
{
	t_fd	*p;

	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p -> next = new;
}
