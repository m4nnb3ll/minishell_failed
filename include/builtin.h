/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:00:21 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 15:32:02 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILTIN_H
# define BUILTIN_H

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
