/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:04:54 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/22 18:48:55 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expander.h"

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
	int	i;
	char *result;

	i = 0;
	if (!str)
		return (0);
	if (str[0])
		i++;
	while (str[i] != '\'' && str[i] != '"' && str[i] != ' ' && str[i] != '$' && str[i] != '=' && str[i])
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

int	check_value(t_expand *expand, char *str)
{
	char	**splited;
	char	*temp;
	t_env	*node;

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
			expand->tmp->content = ft_strjoin(expand->tmp->content, ft_itoa(g_minishell.exit_s));
	}
	if (get_node(temp))
	{
		node = get_node(temp);
		splited = ft_split(node->value, ' ');
		join_value(expand, splited);
	}
	return (ft_strlen(temp));
}

char	**expander(char *str)
{
	t_expand	expand;

	expand.i = 0;
	expand.quotes = 0;
	expand.lst = NULL;
	ft_lstadd_back(&expand.lst, ft_lstnew(NULL));
	expand.tmp = expand.lst;
	while (str && str[expand.i])
	{
		if ((str[expand.i] == '"' || str[expand.i] == '\'') && expand.quotes == 0)	
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
		expand.i++;
	}
	return (put_twod_array(expand.lst));
}
