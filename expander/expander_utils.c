/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:12:26 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 18:40:21 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	put_twod_size(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		if (lst->content)
			len++;
		lst = lst->next;
	}
	return (len);
}

char	**put_twod_array(t_list *lst)
{
	int		len;
	char	**arr;
	int		i;

	i = 0;
	len = put_twod_size(lst);
	arr = malloc((len + 1) * sizeof(char *));
	while (i < len)
	{
		if (lst->content != NULL)
			arr[i] = ft_strdup(lst->content);
		lst = lst->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	*get_var(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (0);
	if (str[0])
		i++;
	while (str[i] != '\'' && str[i] != '"' && str[i] != ' '
		&& str[i] != '$' && str[i] != '=' && str[i])
		i++;
	result = malloc(i + 1);
	ft_strlcpy(result, str, i + 1);
	return (result);
}

char	*char_join(char *str, char c)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	if (!str)
	{
		result = malloc(2);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	len = ft_strlen(str) + 2;
	result = malloc(len);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}

void	join_value(t_expand *expand, char **splited)
{
	if (!expand->tmp->content)
	{
		if (*splited)
			expand->tmp->content = ft_strdup(*splited);
	}
	else
		expand->tmp->content = ft_strjoin(expand->tmp->content, *splited);
	splited++;
	while (splited && *splited)
	{
		ft_lstadd_back(&expand->lst, ft_lstnew(*splited));
		expand->tmp = expand->tmp->next;
		splited++;
	}
}
