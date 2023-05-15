/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:32:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/16 00:51:16 by abelayad         ###   ########.fr       */
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

/*TEMP___START*/
extern char* types[];
/*TEMP___END*/

typedef struct s_minishell
{
	t_token		*tokens;
	t_token		*curr_token;
	t_node		*tree;
	t_parse_err	parse_err;
	t_node		*exit_status;
}	t_minishell;

extern t_minishell	g_minishell;

#endif