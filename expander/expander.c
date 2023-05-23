/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:04:54 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/23 20:01:30 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_value(t_expand *expand, char *str)
{
	char	*temp;

	temp = get_var(str + 1);
	if (temp[0] == '\0' && str[0] == '$')
	{	
		if (!expand->tmp->content)
			expand->tmp->content = ft_strdup("$");
		else
			expand->tmp->content = ft_strjoin(expand->tmp->content, "$");
	}
	else if (str[1] == '?')
	{
		if (!expand->tmp->content)
			expand->tmp->content = ft_strdup(ft_itoa(g_minishell.exit_s));
		else
			expand->tmp->content = ft_strjoin(expand->tmp->content,
					ft_itoa(g_minishell.exit_s));
	}
	if (get_node(temp))
		join_value(expand, ft_split(get_node(temp)->value, ' '));
	return (ft_strlen(temp));
}

char	**expander(char *str)
{
	t_expand	expand;

	expand.i = -1;
	expand.quotes = 0;
	expand.lst = NULL;
	ft_lstadd_back(&expand.lst, ft_lstnew(NULL));
	expand.tmp = expand.lst;
	while (str && str[++(expand.i)])
	{
		if ((str[expand.i] == '"' || str[expand.i] == '\'')
			&& expand.quotes == 0)
			expand.quotes = str[expand.i];
		else if (str[expand.i] == expand.quotes)
			expand.quotes = 0;
		else if (str[expand.i] == '$' && expand.quotes != '\'')
			expand.i += check_value(&expand, str + expand.i);
		else if (expand.quotes || str[expand.i] != ' ')
			expand.tmp->content = char_join(expand.tmp->content, str[expand.i]);
		else if (str[expand.i] == ' ' && !expand.quotes)
		{
			ft_lstadd_back(&expand.lst, ft_lstnew(NULL));
			expand.tmp = expand.tmp->next;
		}
	}
	return (ft_lstclear(&expand.tmp, NULL), put_twod_array(expand.lst));
}
