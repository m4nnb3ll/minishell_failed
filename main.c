/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 01:28:41 by abelayad          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/29 20:14:19 by oakerkao         ###   ########.fr       */
=======
/*   Updated: 2023/05/29 11:46:16 by abelayad         ###   ########.fr       */
>>>>>>> upstream/main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

void	ft_sigint_handler(int num)
{
	(void)num;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_sigquit_handler(int num)
{
	(void)num;
	g_minishell.exit_s = 131;
	printf("Quit: 3\n");
}

void	ft_init_signals(void)
{
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char *argv[], char *env[])
{
	char	**str;

	if (argc > 1)
		return ((void)argv, printf("Too many args\n"), 1);
	get_env_list(env);
	g_minishell.exit_s = 0;
	g_minishell.error_code = SUCCESS;
	while (1)
	{
		ft_init_signals();
		g_minishell.line = readline(PROMPT);
		if (!g_minishell.line)
		{
<<<<<<< HEAD
			//ft_putstr_fd("exit\n", 1);
			//env_clear(&g_minishell.list);
			//ft_clear_ast(&g_minishell.ast);
			exit(g_minishell.exit_s);
=======
			ft_putstr_fd("\nexit\n", 1);
			ft_clear_minishell();
			exit(0);
>>>>>>> upstream/main
		}
		g_minishell.tokens = ft_tokenize();
		if (!g_minishell.tokens)
			continue ;
		g_minishell.ast = ft_parse();
		if (g_minishell.parse_err.type)
			ft_handle_parse_err();
		signal(SIGQUIT, ft_sigquit_handler);
		exec();
<<<<<<< HEAD
		//ft_clear_ast(&g_minishell.ast);
	}
	//env_clear(&g_minishell.list);
=======
		ft_clear_minishell();
	}
>>>>>>> upstream/main
}
