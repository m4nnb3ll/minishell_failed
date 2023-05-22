/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:09:16 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 21:45:02 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct	s_fd
{
	int			content;
	struct s_fd	*next;
} t_fd;

typedef	struct	s_context
{
	int		fd[2];
	t_fd	*fd_close;
	t_fd	*here_doc;
} t_context;

// utils
char	*path_getter(char *cmd);
char	**cmd_getter(char *arg);
char	**put_twod_array(t_list *lst);
char	**twod_split(char *str, char c);
char	*ft_strjoin_o(int size, ...);
t_list	*ft_split_o(char *str, char c);

//functions

void	exec();
int		exec_node(t_node *tree, t_context *ctx);
int		exec_pipe(t_node *tree, t_context *ctx);
int		exec_child(t_node *tree, t_context *ctx);
int		exec_and(t_node *tree, t_context *ctx);
int		exec_or(t_node *tree, t_context *ctx);
int		exec_left(t_node *node, int fd[2]);
int		exec_right(t_node *node, int fd[2]);
int		check_redirection(t_io_node *io, t_context *ctx);

// redirect
int	out(char *file, t_context *ctx);
int	in(char *file, t_context *ctx);
int	append(char *file, t_context *ctx);
int	here_doc(char *delimiter, t_context *ctx);

// error
void	error_msg(char *file, char *err_msg, int exit_code);

// exit_code
void	exit_status(char *path);

// close_fds
void	close_child_fds(t_context *ctx);
void	close_parent_here_doc(t_context *ctx);

// exec_utils
t_fd	*new_list(int content);
void	add_list(t_fd **lst, t_fd *new);

// traverse_tree
void	traverse_tree(t_node *tree, t_context *ctx);
void	traverse_pipe(t_node *tree, t_context *ctx);
void	traverse_child(t_node *tree, t_context *ctx);
void	traverse_and(t_node *tree, t_context *ctx);
void	traverse_or(t_node *tree, t_context *ctx);
# endif
