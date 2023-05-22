/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:32:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/22 10:45:03 by abelayad         ###   ########.fr       */
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
	char		*line;
	char		*error;
	int			exit_s;
	int			*pid;
	int			index;
	bool		sigint;
	t_token		*curr_token;
	t_node		*ast;
	t_parse_err	parse_err;
}					t_minishell;

extern t_minishell	g_minishell;

#endif
