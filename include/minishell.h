/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:32:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/21 19:39:13 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

// MAKE SURE TO PUT THE HEADERS AS A DEPENDENCY

# include <stdbool.h>
# include <readline/readline.h>
# include "libft.h"
# include "tokenizing.h"
# include "parsing.h"
# include "env.h"
# include "exec.h"
# include "builtin.h"
# include "expander.h"

/*TEMP___START*/
extern char			*types[];
/*TEMP___END*/

typedef struct s_minishell
{
	t_token		*tokens;
	t_node		*tree;
	t_env		*list;
	t_node		*exit_status;
	char		*error;
	int			exit_s;
	int			*pid;
	int			index;
	t_token		*curr_token;
	t_node		*ast;
	t_parse_err	parse_err;
}					t_minishell;

extern t_minishell	g_minishell;

#endif
