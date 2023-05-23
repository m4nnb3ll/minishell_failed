/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:32:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 14:43:57 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// MAKE SURE TO PUT THE HEADERS AS A DEPENDENCY

# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "tokenizing.h"
# include "parsing.h"
# include "env.h"
# include "exec.h"
# include "builtin.h"
# include "expander.h"
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

/*TEMP___START*/
extern char			*types[];
/*TEMP___END*/
// EXEC START
typedef struct	s_exec
{
	char	*path;
	char	**args;
} t_exec;

typedef struct	s_fd
{
	int			content;
	struct s_fd	*next;
} t_fd;

typedef	struct	s_context
{
	int	fd[2];
	t_fd	*fd_close;
	t_fd	*here_doc;
} t_context;

// EXEC END

typedef struct s_minishell
{
	t_token		*tokens;
	t_node		*tree;
	t_env		*list;
	char		*line;
	char		*error;
	int			exit_s;
	int			*pid;
	int			index;
	bool		sigint;
	t_token		*curr_token;
	t_node		*ast;
	t_exec		exec;
	int	in_pipe;
	t_parse_err	parse_err;
}					t_minishell;

extern t_minishell	g_minishell;

// EXECUTION START

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

//builtins
int	is_builtin_child();

// error
void	error_msg(char *file, char *err_msg, int exit_code);

// exit_code
void	exit_status();

// close_fds
void	close_child_fds(t_context *ctx);
void	close_parent_here_doc(t_context *ctx);

// exec_utils
t_fd	*new_list(int content);
void	add_list(t_fd **lst, t_fd *new);
void	exec_init(void);

// traverse_tree
void	traverse_tree(t_node *tree, t_context *ctx);
void	traverse_pipe(t_node *tree, t_context *ctx);
void	traverse_child(t_node *tree, t_context *ctx);
void	traverse_and(t_node *tree, t_context *ctx);
void	traverse_or(t_node *tree, t_context *ctx);
// EXECUTION END



#endif
