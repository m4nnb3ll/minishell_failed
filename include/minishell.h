/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:32:13 by abelayad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 18:28:46 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/23 19:37:02 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"
# include "tokenizing.h"
# include "parsing.h"

// ENV START
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// EXEC START
typedef struct s_wait
{
	int	i;
	int	status;
	int	child;
}	t_wait;
typedef struct s_exec
{
	char	*path;
	char	**args;
}	t_exec;

typedef struct s_fd
{
	int			content;
	struct s_fd	*next;
}	t_fd;

typedef struct s_context
{
	int		fd[2];
	t_fd	*fd_close;
	t_fd	*here_doc;
}	t_context;

<<<<<<< HEAD
typedef enum s_error
{
	SUCCESS,
	CMD_NOT_FOUND,
	NO_SUCH_FILE_FILE,
	NO_SUCH_FILE_PROGRAM,
	PERMISSION_DENIED_FILE,
	PERMISSION_DENIED_PROGRAM,
	AMBIGUOUS
} t_error;

// EXEC END
=======
// EXPANDER START
typedef struct s_expand
{
	t_list	*lst;
	t_list	*tmp;
	char	quotes;
	int		i;
}	t_expand;
// EXPANDER END
>>>>>>> upstream/main

typedef struct s_minishell
{
	t_token		*tokens;
	t_env		*env_list;
	char		*line;
	int			exit_s;
	int			index;
	bool		sigint;
	t_token		*curr_token;
	t_node		*ast;
	t_exec		exec;
	int			in_pipe;
	int			in_redirect;
	t_error	error_code;
	char	*error_file;
	t_parse_err	parse_err;
}					t_minishell;

extern t_minishell	g_minishell;

<<<<<<< HEAD
// EXECUTION START

// utils
char	*path_getter(char *cmd);
char	**cmd_getter(char *arg);
char	**put_twod_array(t_list **lst);
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
void	check_redirection(t_io_node *io, t_context *ctx);

// redirect
void	out(char *file, t_context *ctx);
void	in(char *file, t_context *ctx);
void	append(char *file, t_context *ctx);
void	here_doc(char *delimiter, t_context *ctx);

//builtins
int	is_builtin_child();
void	exec_builtin_parent();
int	is_builtin_parent();
void	exec_builtin_child();
int	is_builtin_child();

// error
void	error_msg();

// exit_code
void	exit_status();

// close_fds
void	exec_dup(t_context *ctx);
=======
// BUILTS-INS START
void	change_pwd(void);
void	change_old_pwd(void);
void	change_to_home(void);
void	cd(char *path);
int		check_flag(char *str);
void	echo(char **cmd);
void	env(void);
void	exit_error_msg(char *str);
int		check_exit_arg(char *str);
void	ft_exit(char **args);
void	export_error_msg(char *identifier);
void	export_list(void);
int		check_key(char *str);
void	export(char **argv);
void	pwd(void);
void	remove_node(char *key);
void	unset(char **args);
int		is_valid(char *str, int sign);
int		is_number(char *str);
int		check_long(unsigned long long res, int sign);

// ENV START
t_env	*new_node(char *key, char *value);
void	add_node(t_env *new);
void	print_env_list(void);
int		env_list_size(t_env *list);
char	*get_key(char *str);
char	*get_value(char *str);
void	get_env_list(char **enviro);
t_env	*get_node(char *key);
void	env_clear(t_env **env);

// EXECUTION START
>>>>>>> upstream/main
void	close_child_fds(t_context *ctx);
void	close_parent_here_doc(t_context *ctx);
char	**str_to_twod(char *str);
char	**cmd_getter(char *arg);
void	error_msg(char *file, char *err_msg, int exit_code);
int		is_builtin_child(void);
int		check_redirection(t_io_node *io, t_context *ctx);
void	exec_builtin_child(void);
void	here_doc_content(t_context *ctx);
void	exec_child_helper(t_context **ctx, int redirect);
int		exec_child(t_node *tree, t_context *ctx);
int		exec_pipe(t_node *tree, t_context *ctx);
int		out(char *file, t_context *ctx);
int		in(char *file, t_context *ctx);
int		append(char *file, t_context *ctx);
int		here_doc(char *delimiter, t_context *ctx);
void	exec_init(t_context *ctx, t_wait *wait_var);
t_fd	*new_list(int content);
void	add_list(t_fd **lst, t_fd *new);
void	free_twod_array(char **arr);
<<<<<<< HEAD
void	free_ever();

//exec read write
void	check_exec(char *file);
void	check_program(char *file);
void	check_read(char *file);
void	check_write(char *file);
void	ambiguous_checking(char *file);

// traverse_tree
=======
void	exec(void);
int		exec_node(t_node *tree, t_context *ctx);
int		exec_and(t_node *tree, t_context *ctx);
int		exec_or(t_node *tree, t_context *ctx);
void	exit_status(void);
char	*check_cmd(char *cmd, char *path);
int		check_existence(char *cmd);
char	*check_path(char *cmd, char *env);
char	*path_getter(char *cmd);
>>>>>>> upstream/main
void	traverse_tree(t_node *tree, t_context *ctx);
void	traverse_pipe(t_node *tree, t_context *ctx);
void	traverse_child(t_node *tree, t_context *ctx);
void	traverse_and(t_node *tree, t_context *ctx);
void	traverse_or(t_node *tree, t_context *ctx);

// EXPANDER START
int		put_twod_size(t_list *lst);
char	**put_twod_array(t_list *lst);
char	*get_var(char *str);
char	*char_join(char *str, char c);
void	join_value(t_expand *expand, char **splited);
int		check_value(t_expand *expand, char *str);
char	**expander(char *str);
// CLEARING
void	ft_free_exec(void);
void	ft_clear_minishell(void);

#endif