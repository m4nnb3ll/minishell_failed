/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:41:11 by abelayad          #+#    #+#             */
/*   Updated: 2023/04/12 21:41:36 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	ft_handle_space(char **str_ptr, t_token **token_list)
{
	t_token	*lst_token;

	lst_token = ft_new_token(NULL, T_SPACE);
	if (!lst_token)
		return (0);
	ft_append_token(token_list, lst_token);
	while (**str_ptr && ft_isspace(**str_ptr))
		(*str_ptr)++;
	return (1);
}

int	ft_handle_quotes(char **str_ptr, t_token **token_list)
{
	if (ft_strchr(*str_ptr + 1, **str_ptr))
		return (ft_append_quoted_str(str_ptr, token_list) && 1);
	else
		return (ft_append_identifier(str_ptr, token_list) && 1);
}

int	ft_handle_dollar(char **str, t_token **token_list)
{
	char	*value;
	t_token	*lst_token;

	if (*(*str + 1) == '$')
	{
		value = ft_strdup("$$");
		if (!value)
			return (0);
		lst_token = ft_new_token(value, T_DOLLAR);
		if (!lst_token)
			return (free(value), 0);
		ft_append_token(token_list, lst_token);
		*str += 2;
	}
	else if (!ft_append_dollar_str(str, token_list))
		return (0);
	return (1);
}

int	ft_handle_separator(char **line, t_token **token_list)
{
	if (!ft_strncmp(*line, "<<", 2))
		return (ft_append_separator(T_HEREDOC, line, token_list) && 1);
	else if (!ft_strncmp(*line, ">>", 2))
		return (ft_append_separator(T_APPEND, line, token_list) && 1);
	else if (!ft_strncmp(*line, "<", 1))
		return (ft_append_separator(T_IN_REDIR, line, token_list) && 1);
	else if (!ft_strncmp(*line, ">", 1))
		return (ft_append_separator(T_OUT_REDIR, line, token_list) && 1);
	else
		return (ft_append_separator(T_PIPE, line, token_list) && 1);
}

t_token	*ft_tokenization_handler(char *line)
{
	int		error;
	t_token	*token_list;

	error = 0;
	token_list = NULL;
	while (*line)
	{
		if (error)
			return (ft_clear_token_list(&token_list), NULL);
		if (ft_isspace(*line))
			error = (!ft_handle_space(&line, &token_list) && 1);
		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
			|| !ft_strncmp(line, "|", 1))
			error = (!ft_handle_separator(&line, &token_list) && 1);
		else if (!ft_strncmp(line, "'", 1) || !ft_strncmp(line, "\"", 1))
			error = (!ft_handle_quotes(&line, &token_list) && 1);
		else if (!ft_strncmp(line, "$", 1))
			error = (!ft_handle_dollar(&line, &token_list) && 1);
		else
			error = (!ft_append_identifier(&line, &token_list) && 1);
	}
	return (token_list);
}
