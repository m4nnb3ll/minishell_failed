/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:04:54 by oakerkao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 19:03:57 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expander.h"
# include <string.h>

int	put_twod_size(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

char	**put_twod_array(t_list **lst)
{
	int		len;
	char	**arr;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	len = put_twod_size(tmp);
	arr = malloc((len + 1) * sizeof(char *));
	while (tmp) 
	{
		if (tmp->content != NULL)
		{
			arr[i] = ft_strdup(tmp->content);
			i++;
		}
		tmp = tmp->next;
	}
	arr[i] = NULL;
	/*while (*arr)
	{
		printf("%s\n", *arr);	
		arr++;
	}
	exit(0);
	*/
	ft_lstclear(lst, free);
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
	if (str == NULL)
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
	free(str);
	return (result);
}

int	check_last(char *str)
{
	size_t len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (str[len - 1] == ' ')
		return (1);
	return (0);
}

void	join_value(t_expand *expand, char *value)
{
	char	**splited;
	char	*tmp;

	splited = ft_split(value, ' ');
	if (value && ft_isspace(*value) == 0 && *splited)
	{
		if (expand->tmp && !expand->tmp->content)
			expand->tmp->content = *splited;
		else if (expand->tmp && expand->tmp->content)	
		{
			tmp = expand->tmp->content;
			expand->tmp->content = ft_strjoin(tmp, *splited);
			free(*splited);
			free(tmp);
		}
		splited++;
	}
	while (splited && *splited)
	{
		ft_lstadd_back(&expand->lst, ft_lstnew(*splited));
		expand->tmp = expand->tmp->next;
		splited++;	
	}
	if (value && check_last(value) == 1)
	{
		ft_lstadd_back(&expand->lst, ft_lstnew(NULL));
		expand->tmp = expand->tmp->next;
	}
}
=======
/*   Updated: 2023/05/23 20:01:30 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
>>>>>>> upstream/main

int	check_value(t_expand *expand, char *str)
{
	char	*temp;
<<<<<<< HEAD
	char	*tmp;
	t_env	*node;
	int	len;
=======
>>>>>>> upstream/main

	temp = get_var(str + 1);
	if (temp[0] == '\0' && str[0] == '$')
	{	
		if (!expand->tmp->content)
			expand->tmp->content = ft_strdup("$");
		else
		{
			tmp = expand->tmp->content;
			expand->tmp->content = ft_strjoin(tmp, "$");
			free(tmp);
		}
		return (1);
	}
	else if (str[1] == '?')
	{
		if (!expand->tmp->content)
			expand->tmp->content = ft_strdup(ft_itoa(g_minishell.exit_s));
		else
<<<<<<< HEAD
			expand->tmp->content = ft_strjoin(expand->tmp->content, ft_itoa(g_minishell.exit_s));
		return (1);
	}
	else if (get_node(temp))
	{
		node = get_node(temp);
		join_value(expand, node->value);
	}
	len = ft_strlen(temp);
	free(temp);
	return (len);
=======
			expand->tmp->content = ft_strjoin(expand->tmp->content,
					ft_itoa(g_minishell.exit_s));
	}
	if (get_node(temp))
		join_value(expand, ft_split(get_node(temp)->value, ' '));
	return (ft_strlen(temp));
>>>>>>> upstream/main
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
<<<<<<< HEAD
		if ((str[expand.i] == '"' || str[expand.i] == '\'') && expand.quotes == 0)	
		{
			expand.tmp->content = char_join(expand.tmp->content, '\0');
=======
		if ((str[expand.i] == '"' || str[expand.i] == '\'')
			&& expand.quotes == 0)
>>>>>>> upstream/main
			expand.quotes = str[expand.i];
		}
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
<<<<<<< HEAD
	return (put_twod_array(&expand.lst));
=======
	return (ft_lstclear(&expand.tmp, NULL), put_twod_array(expand.lst));
>>>>>>> upstream/main
}
