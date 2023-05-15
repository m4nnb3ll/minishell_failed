/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:28:41 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/16 00:49:44 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

/*TEMP___START*/
char* types[] = {
	"T_IDENTIFIER",
	"<",
	">",
	"<<",
	">>",
	"|",
	"OP",
	"CP",
	"&&",
	"||",
	"newline"
};
/*TEMP___START*/

void	print_tree(t_node *node);

void	ft_handle_parse_err()
{
	t_parse_err_type	type;
	t_token_type		token_type;

	type = g_minishell.parse_err.type;
	if (type)
	{
		// ft_clear_ast(); //TO HANDLE LATER
		if (type == E_SYNTAX)
		{
			if (!g_minishell.curr_token)
				token_type = T_NL;
			else
				token_type = g_minishell.curr_token->type;
			ft_putstr_fd("msh: syntax error near unexpected token `", 2);
			ft_putstr_fd(types[token_type], 2);
			ft_putstr_fd("'\n", 2);
		}
		ft_bzero(&g_minishell.parse_err, sizeof(t_parse_err));
	}
}

int	main()
{
	// printf("%s\n", BABOCHA_LOGO);
	g_minishell.tokens = ft_tokenize();
	if (!g_minishell.tokens)
		return (1);
	printf("Pass\n");
	// ft_clear_token_list(&g_minishell.tokens);
	// if (g_minishell.tokens)
	g_minishell.tree = ft_parse();
	if (!g_minishell.tree)
		ft_handle_parse_err();
	// print_tree(g_minishell.tree);
}