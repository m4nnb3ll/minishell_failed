/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:41:48 by abelayad          #+#    #+#             */
/*   Updated: 2023/04/12 20:46:28 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '<'
		|| c == '>' || c == '|' || c == '$')
		return (1);
	return (0);
}
