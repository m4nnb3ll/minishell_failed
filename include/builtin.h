/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:00:21 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/16 18:33:19 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILTIN_H
# define BUILTIN_H

# include <string.h>
# include "minishell.h"

void	unset(char **args);
void	echo(char **cmd);
void	export(char **argv);
void	env(void);
void	pwd(void);
void	cd(char *path);
void	ft_exit(char **args);

/* utils */
int		check_key(char *str);

# endif
