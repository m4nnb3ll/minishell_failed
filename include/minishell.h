/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:32:13 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/15 15:33:50 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <readline/readline.h>
# include "libft.h"
# include "tokenizing.h"
# include "parsing.h"

typedef struct s_minishell
{
	t_token	*tokens;
	t_node	*tree;
	t_node	*exit_status;
	char	*error;
}	t_minishell;

t_minishell	minishell;

#endif