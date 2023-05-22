/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:57:54 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/22 15:59:51 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

typedef struct	s_expand	
{
	t_list	*lst;
	t_list	*tmp;
	char	quotes;
	int		i;
} t_expand;

char	**expander(char *str);

# endif
