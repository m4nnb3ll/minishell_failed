/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:16:20 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 12:05:29 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	export_error_msg(char *identifier)
{
	ft_putstr_fd("minishell: export: `", 1);
	ft_putstr_fd(identifier, 1);
	ft_putstr_fd("': not a valid identifier\n", 1);
}

void	export_list()
{
	t_env	*list = g_minishell.list;
	while (list)
	{
		if (list->value != NULL)
			printf("declare -x %s=\"%s\"\n", list->key, list->value);
		else
			printf("declare -x %s\n", list->key);
		list = list->next;
	}
}

int	check_key(char *str)
{
	int	i;

	i = 1;
	if ((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A' || str[0] > 'Z') \
			&& str[0] != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && \
				(str[i] < '0' || str[i] > '9') && (str[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}

void	export(char **argv)
{
	int		i;
	t_env	*tmp;
	i = 1;
	if (!argv[i])
	{
		export_list();
		return ;
	}
	while (argv[i])
	{
		if (check_key(argv[i]) == 0)
			export_error_msg(argv[i]);
		else if (get_node(get_key(argv[i])))
		{
			tmp = get_node(get_key(argv[i]));
			if (get_value(argv[i]))
				tmp->value = get_value(argv[i]);
			return ;
		}
		else
			add_node(new_node(get_key(argv[i]), get_value(argv[i])));
		i++;
	}
}
