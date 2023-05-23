/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:52:56 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 15:56:13 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUFFER_SIZE 10

t_token	*ft_tokenize(void)
{
	char	*line;
	t_token	*token_list;
	
	// if (isatty(0))
	// 	line = readline(PROMPT);
	// else
	// 	line = get_next_line(0);
	line = g_minishell.line;
	token_list = ft_tokenization_handler(line);
	add_history(line);
	return (free(line), token_list);
}





// GET_NEXT_LINE BELOW













char	*str_res(char *str1, char *str2);
char	*str_rem(char *str);
char	*str_save(char	*str);
char	*str_dup(char *str);
char	*read_check(int fd, char *result);
char	*get_next_line(int fd);
char	*str_res(char *str1, char *str2)
{
	char	*res_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str1 == NULL && str2 != NULL)
		return (str_dup(str2));
	else if (str1 != NULL && str2 != NULL)
	{
		res_str = (char *)malloc((ft_strlen(str1) + \
					ft_strlen(str2) + 1) * sizeof(char));
		if (!res_str)
			return (0);
		while (str1[j])
			res_str[i++] = str1[j++];
		j = 0;
		while (str2[j])
			res_str[i++] = str2[j++];
		res_str[i] = '\0';
		free(str1);
	}
	else
		return (0);
	return (res_str);
}

char	*str_rem(char *str)
{
	char	*rem_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	rem_str = (char *)malloc((i + 1) * sizeof(char));
	if (!rem_str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rem_str[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		rem_str[i] = str[i];
		rem_str[++i] = '\0';
	}
	else
		rem_str[i] = '\0';
	return (rem_str);
}

char	*str_save(char	*str)
{
	char	*save_str;
	int		i;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i])
	{
		save_str = malloc((len - i) + 1);
		if (!save_str)
			return (0);
		while (str[i])
			save_str[j++] = str[i++];
		save_str[j] = '\0';
		free(str);
		return (save_str);
	}
	free(str);
	return (0);
}

char	*str_dup(char *str)
{
	char	*res_str;
	int		i;

	i = 0;
	res_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i])
	{
		res_str[i] = str[i];
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}

char	*read_check(int fd, char *result)
{
	char	*str;
	int		ret;

	ret = 1;
	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	while (ret > 0)
	{
		ret = read(fd, str, BUFFER_SIZE);
		if (ret == 0 || (ret == -1 && !result))
			break ;
		if (ret == -1 && result)
		{
			free(result);
			result = NULL;
			break ;
		}
		str[ret] = '\0';
		result = str_res(result, str);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*final;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (0);
	result = read_check(fd, result);
	if (!result)
		return (0);
	final = str_rem(result);
	result = str_save(result);
	return (final);
}
