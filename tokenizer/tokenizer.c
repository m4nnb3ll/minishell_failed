/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:52:56 by abelayad          #+#    #+#             */
/*   Updated: 2023/04/12 22:15:12 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_token	*ft_tokenize(void)
{
	char	*line;
	t_token	*token_list;

	line = readline("b3bola# ");
	if (!line)
		return (NULL);
	token_list = ft_tokenization_handler(line);
	return (free(line), token_list);
}
