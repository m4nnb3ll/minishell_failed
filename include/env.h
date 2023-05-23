/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:41:01 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 15:32:08 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

typedef	struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;
# include "minishell.h"
t_env	*new_node(char *key, char *value);
void	add_node(t_env *new);
void	print_env_list(void);
int		env_list_size(t_env *list);
char	*get_key(char *str);
char	*get_value(char *str);
void	get_env_list(char **enviro);
t_env	*get_node(char *key);

#endif
