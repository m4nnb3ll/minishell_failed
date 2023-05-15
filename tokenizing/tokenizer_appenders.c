/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_appenders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:45:29 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/15 15:33:25 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_append_separator(t_type type, char **line_ptr, t_token **token_list)
{
	t_token	*token;

	token = ft_new_token(NULL, type);
	if (!token)
		return (0);
	ft_append_token(token_list, token);
	(*line_ptr)++;
	if (type == T_DLESS || type == T_DGREAT || type == T_OR || type == T_AND)
		(*line_ptr)++;
	return (1);
}

bool	ft_skip_quotes(char *line, size_t *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + *i + 1, quote))
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		(*i)++;
		return (true);
	}
	return (false);
}

int	ft_append_identifier(char **line_ptr, t_token **token_list)
{
	char	*tmp_line;
	char	*value;
	t_token	*token;
	size_t	i;

	tmp_line = *line_ptr;
	i = 0;
	while (tmp_line[i] && !ft_is_separator(tmp_line[i]))
	{
		if (ft_is_quote(tmp_line[i]))
		{
			if (!ft_skip_quotes(tmp_line, &i))
				return (ft_putstr_fd(QUOTE_ERR, 2), 0);
		}
		else
			i++;
	}
	value = ft_substr(tmp_line, 0, i);
	if (!value)
		return (0);
	token = ft_new_token(value, T_IDENTIFIER);
	if (!token)
		return (free(value), 0);
	*line_ptr += i;
	return (ft_append_token(token_list, token), 1);
}
