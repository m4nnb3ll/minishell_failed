/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:32:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 18:43:53 by abelayad         ###   ########.fr       */
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

// EXPANDER START
typedef struct s_expand
{
	t_list	*lst;
	t_list	*tmp;
	char	quotes;
	int		i;
}	t_expand;
// EXPANDER END

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
	int			in_pipe;
	t_parse_err	parse_err;
}					t_minishell;

extern t_minishell	g_minishell;

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
void	exec(void);
int		exec_node(t_node *tree, t_context *ctx);
int		exec_and(t_node *tree, t_context *ctx);
int		exec_or(t_node *tree, t_context *ctx);
void	exit_status(void);
char	*check_cmd(char *cmd, char *path);
int		check_existence(char *cmd);
char	*check_path(char *cmd, char *env);
char	*path_getter(char *cmd);
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
// EXPANDER END

#endif