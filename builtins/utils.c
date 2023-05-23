/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:21:45 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 16:31:52 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid(char *str, int sign)
{
	int					i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (res > res * 10 + (str[i] - 48))
			return (0);
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (check_long(res, sign));
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_long(unsigned long long res, int sign)
{
	if (res > 9223372036854775807 && sign == 1)
		return (0);
	else if (res > 9223372036854775808UL && sign == -1)
		return (0);
	return (1);
}
