/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:04:54 by oakerkao          #+#    #+#             */
/*   Updated: 2023/05/21 18:08:11 by oakerkao         ###   ########.fr       */
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
	while (str[i] != '\'' && str[i] != '"' && str[i] != ' ' && str[i] != '$' && str[i])
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

int	check_value(t_list **lst, char *str, int i, t_list **tmp)
{
	char	**splited;
	char	*temp;
	t_env	*node;
	int	j;
	int	k;

	j = 1;
	k = 0;
	temp = get_var(str + 1);
	i = 0;
	i += ft_strlen(temp);
	if (get_node(temp))
	{
		node = get_node(temp);
		splited = ft_split(node->value, ' ');
		if ((*tmp)->content == NULL)
			(*tmp)->content = ft_strdup(splited[0]);
		else
			(*tmp)->content = ft_strjoin((*tmp)->content, splited[0]);
		while (splited && splited[j])
		{
			ft_lstadd_back(lst, ft_lstnew(splited[j]));
			(*tmp) = (*tmp)->next;
			j++;
		}
	}
	else if (ft_strcmp(str + 1, "?") == 0)
	{
		if ((*tmp)->content == NULL)
			(*tmp)->content = ft_strdup(ft_itoa(g_minishell.exit_s));
		else
			(*tmp)->content = ft_strjoin((*tmp)->content, ft_itoa(g_minishell.exit_s));
	}
	else if (ft_strcmp(str, "$") == 0)
		(*tmp)->content = char_join((*tmp)->content, '$');
	return (i);
}

char	**expander(char *str)
{
	char	quotes;
	int		i;
	t_list	*lst;
	t_list	*tmp;
	char	**splited;

	i = 0;
	quotes = 0;
	lst = NULL;
	tmp = NULL;
	splited = NULL;
	ft_lstadd_back(&lst, ft_lstnew(NULL));
	tmp = lst;
	while (str && str[i])
	{
		if ((str[i] == '"' || str[i] == '\'') && quotes == 0)	
			quotes = str[i];
		else if (str[i] == quotes)
			quotes = 0;
		else if (str[i] == '$' && quotes != '\'')
		{
			i += check_value(&lst, str + i, i, &tmp);
		}
		else if (quotes || str[i] != ' ')
			tmp->content = char_join(tmp->content, str[i]);
		else if (str[i] == ' ' && !quotes)
		{
			ft_lstadd_back(&lst, ft_lstnew(NULL));
			tmp = tmp->next;
		}
		i++;
	}
	/*while (lst)
	{
		if (lst->content)
			printf("%s\n", lst->content);
		lst = lst->next;	
	}*/
	splited = put_twod_array(lst);
	return (splited);
}

/*int main(int argc, char *argv[])
{
	char **arr = expander(argv[1]);
	while (arr && *arr)
	{
		printf("%s\n", *arr);	
		arr++;
	}
}*/
