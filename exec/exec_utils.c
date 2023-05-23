/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:59:15 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 18:07:10 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_init(t_context *ctx, t_wait *wait_var)
{
	wait_var->i = 0;
	wait_var->child = 0;
	wait_var->status = 0;
	g_minishell.exec.path = NULL;
	g_minishell.exec.args = NULL;
	g_minishell.index = 0;
	g_minishell.in_pipe = 0;
	ctx->fd[0] = 0;
	ctx->fd[1] = 1;
	ctx->fd_close = NULL;
	ctx->here_doc = NULL;
}

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

void	free_twod_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
