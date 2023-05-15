// #include "minishell.h"
// #include "minishell.h"

// t_token *token;

// // Helper functions START

// int	is_io_redirect(t_token_type type)
// {
// 	if (type == T_IN_REDIR
// 		|| type == T_OUT_REDIR
// 		|| type == T_APPEND
// 		|| type == T_HEREDOC
// 	)
// 		return (1);
// 	return (0);
// }

// int	is_word(t_token_type type)
// {
// 	if (type == T_IDENTIFIER
// 		|| type == T_S_QUOTE
// 		|| type == T_APPEND
// 		|| type == T_DOLLAR
// 	)
// 		return (1);
// 	return (0);
// }

// // Helper functions END

// void	command_line();
// void	pipeline();
// void	pipeline_p();
// void	command();
// void	io_redirect();
// void	word();


// void	command_line()
// {
// 	pipeline();
// }

// void	pipeline()
// {
// 	command();
// 	pipeline_p();
// }

// void	pipeline_p()
// {
// 	if (token && token->type == T_PIPE)
// 	{
// 		token = token->next;
// 		command();
// 		pipeline_p();
// 	}
// 	else
// 		return ;
// }

// void	command()
// {
// 	if (token && is_io_redirect(token->type))
// 	{
// 		io_redirect();
// 		command();
// 	}
// 	else if (token && is_word(token->type))
// 	{
// 		word();
// 		command();
// 	}
// 	else
// 		return ;
// }

// void	io_redirect()
// {
// 	if (token->type == T_IN_REDIR || token->type == T_OUT_REDIR
// 		|| token->type == T_APPEND || token->type == T_HEREDOC)
// 	{
// 		token = token -> next;
// 	}
// 	else
// 		return ;
// }

// void	word()
// {
// 	if (token && token->type == T_IDENTIFIER)
// 	{
// 		token = token -> next;
// 	}
// 	else if (token && token->type == T_S_QUOTE)
// 	{
// 		token = token -> next;
// 	}
// 	else if (token && token->type == T_D_QUOTE)
// 	{
// 		token = token -> next;
// 	}
// 	else if (token && token->type == T_DOLLAR)
// 	{
// 		token = token -> next;
// 	}
// 	else
// 		return ;
// }

// int main()
// {
// 	// t_node	*tree;

// 	token = ft_tokenize();
// 	command_line();
// 	if (!token)
// 	{
// 		printf("parsed successfully\n");
// 		// printf("%d %s\n", token->type, token->value);
// 	}
// 	else
// 	{
// 		printf("token type is: %d\n token value is: %s\n", token->type, token->value);
// 		printf("error parsing\n");
// 		// printf("%d %s\n", token->type, token->value);
// 	}
// }