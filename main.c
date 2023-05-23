/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:28:41 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/23 12:04:25 by oakerkao         ###   ########.fr       */
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

void	ft_sigint_handler()
{
	ft_putstr_fd("\n", 1);
	//rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_init_signals()
{
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;
	get_env_list(env);
	g_minishell.exit_s = 0;
	ft_init_signals();
	while (1)
	{
		g_minishell.line = readline(PROMPT);
		if (!g_minishell.line)
		{
			ft_putstr_fd("exit\n", 1);
			env_clear(&g_minishell.list);
			ft_clear_ast(&g_minishell.ast);
			exit(1);
		}
		g_minishell.tokens = ft_tokenize();
		if (!g_minishell.tokens)
			continue ;
		g_minishell.ast = ft_parse();
		if (g_minishell.parse_err.type)
			ft_handle_parse_err();
		exec();
		ft_clear_ast(&g_minishell.ast);
	}
	env_clear(&g_minishell.list);
}
