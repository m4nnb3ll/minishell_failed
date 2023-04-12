/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_appenders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:45:29 by abelayad          #+#    #+#             */
/*   Updated: 2023/04/12 20:46:21 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	ft_append_separator(t_type type, char **str_ptr, t_token **token_list)
{
	t_token	*token;

	token = ft_new_token(NULL, type);
	if (!token)
		return (0);
	ft_append_token(token_list, token);
	(*str_ptr)++;
	if (type == T_HEREDOC || type == T_APPEND)
		(*str_ptr)++;
	return (1);
}

int	ft_append_quoted_str(char **str_ptr, t_token **token_list)
{
	char	*value;
	t_token	*lst_token;
	size_t	i;
	t_type	type;

	type = T_S_QUOTE;
	if (**str_ptr == '\"')
		type = T_D_QUOTE;
	i = 0;
	while ((*str_ptr + 1)[i] != **str_ptr)
		i++;
	value = ft_substr(*str_ptr, 0, i + 2);
	if (!value)
		return (0);
	lst_token = ft_new_token(value, type);
	if (!lst_token)
		return (free(value), 0);
	ft_append_token(token_list, lst_token);
	*str_ptr += i + 2;
	return (1);
}

int	ft_append_dollar_str(char **str, t_token **token_list)
{
	char	*value;
	t_token	*lst_token;
	size_t	i;

	i = 0;
	while ((*str + 1)[i] && !ft_is_separator((*str + 1)[i])
			&& !ft_is_quote((*str + 1)[i]))
		i++;
	value = ft_substr(*str, 0, i + 1);
	if (!value)
		return (0);
	lst_token = ft_new_token(value, T_DOLLAR);
	if (!lst_token)
		return (free(value), 0);
	ft_append_token(token_list, lst_token);
	*str += i + 1;
	return (1);
}

int	ft_append_identifier(char **str_ptr, t_token **token_list)
{
	char	*value;
	t_token	*token;
	size_t	i;

	i = 0;
	while ((*str_ptr + 1)[i] && !ft_is_separator((*str_ptr + 1)[i]))
	{
		if (ft_is_quote((*str_ptr + 1)[i])
			&& ft_strchr(*str_ptr + i + 2, (*str_ptr + 1)[i]))
			break ;
		i++;
	}
	value = ft_substr(*str_ptr, 0, i + 1);
	if (!value)
		return (0);
	token = ft_new_token(value, T_IDENTIFIER);
	if (!token)
		return (free(value), 0);
	ft_append_token(token_list, token);
	*str_ptr += i + 1;
	return (1);
}
