/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:28:41 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/17 03:49:32 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

void	print_tokens(t_token *tokens)
{
	t_token *tmp;
	char *types[] = {"T_IDENTIFIER",
		"<", ">", "<<", ">>", "|", "(", ")", "&&", "||", "newline"};

	tmp = tokens;
	while (tmp)
	{
		printf("%s ", types[tmp->type]);
		tmp = tmp -> next;
	}
	printf("\n");
}


int	main()
{
	// printf("%s\n", BABOCHA_LOGO);
	while (1)
	{
		g_minishell.tokens = ft_tokenize();
		if (!g_minishell.tokens)
			continue;
		// print_tokens(g_minishell.tokens);
		g_minishell.ast = ft_parse();
		// print_ast(g_minishell.ast);
		if (g_minishell.parse_err.type)
		{
			// printf(" i get inside\n");
			ft_handle_parse_err();
			ft_clear_token_list(&g_minishell.tokens);
		}
		ft_clear_ast(&g_minishell.ast);
		ft_clear_token_list(&g_minishell.tokens);
		printf("clear exit\n");
		// ft_clear_ast(&g_minishell.ast);// MAKE SURE THAT THIS FUNCTION IS RUN
	}
	// print_ast(g_minishell.ast);
}