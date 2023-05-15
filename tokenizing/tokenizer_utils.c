/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:41:48 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/15 15:33:25 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '<'
		|| c == '>' || c == '|' || c == '$'
		|| c == '(' || c == ')' || c == '&')
		return (1);
	return (0);
}

void	ft_skip_spaces(char **line)
{
	while (**line && ft_isspace(**line))
				(*line)++;
}