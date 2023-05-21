/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:54:18 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 16:07:20 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "exec.h"

void	close_child_fds(t_context *ctx)
{
	t_fd	*close_fd;
	t_fd	*close_pipe;

	close_fd = ctx->here_doc;
	close_pipe = ctx->fd_close;
	while (close_fd)
	{
		close(close_fd->content);	
		close_fd = close_fd->next;
	}
	while (close_pipe)
	{
		close(close_pipe->content);
		close_pipe = close_pipe->next;	
	}
}

void	close_parent_here_doc(t_context *ctx)
{
	t_fd	*close_fd;

	close_fd = ctx->here_doc;
	while (close_fd)
	{
		close(close_fd->content);	
		close_fd = close_fd->next;
	}
}
