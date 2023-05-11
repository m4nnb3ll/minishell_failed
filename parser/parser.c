#include "tokenizer.h"
#include "parser.h"

// t_token *token;
// t_node	*tree = NULL;

// t_node	*command_line();
// t_node	*pipeline();
// t_node	*pipeline_p();
// t_node	*command();
// t_node	*command_p();
// t_node	*cmd_prefix();
// t_node	*cmd_name();
// t_node	*cmd_suffix();
// t_node	*io_redirect();
// t_node	*word();

// // Helper functions START


// // THERE IS A SEGFAULT IN PIPELINE
// // EX: echo hello |


// int	is_io_redirect(t_type type)
// {
// 	if (type == T_IN_REDIR
// 		|| type == T_OUT_REDIR
// 		|| type == T_APPEND
// 		|| type == T_HEREDOC
// 	)
// 		return (1);
// 	return (0);
// }

// int	is_word(t_type type)
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

// t_node	*command_line()
// {
// 	return (pipeline());
// }

// t_node	*pipeline()
// {
// 	return (pipeline_p(command()));
// }

// t_node	*pipeline_p(t_node	*left)
// {
// 	t_node	*node;

// 	if (token && token->type == T_PIPE)
// 	{
// 		node = ft_new_node(NULL, token->type);
// 		node -> left = left;
// 		node -> right = pipeline_p(command());
// 		token = token -> next;
// 		return (node);
// 	}
// 	else
// 		return (left); //epsilon
// }

// t_node	*command()
// {
// 	return (command_p(cmd_prefix()));
// }

// t_node	*command_p(t_node	*left)
// {
// 	t_node	*node;

// 	if (token)
// 	{
// 		node = ft_new_node(NULL, 0);
// 		node -> left = left;
// 		node -> right = command_p(cmd_suffix(cmd_name()));
// 		// cmd_name();
// 		// cmd_suffix();
// 		// command_p();
// 		return (node);
// 	}
// 	else
// 		return (left);
// }

// t_node	*cmd_prefix()
// {
// 	t_node	*node;

// 	if (token && is_io_redirect(token->type))
// 	{
// 		node = ft_new_node(NULL, 0);
// 		node -> left = io_redirect();
// 		node -> right = cmd_prefix();
// 		return node;
// 	}
// 	else if (token && is_word(token->type))
// 	{
// 		node = ft_new_node(NULL, 0);
// 		node -> left = word();
// 		node -> right = cmd_prefix();
// 		return node;
// 	}
// 	else
// 		return NULL;//epsilon
// }

// t_node	*cmd_name()
// {
// 	t_node	*node;

// 	node = ft_new_node(NULL, 0);
// 	node -> left = word();
// 	return node;
// }

// t_node	*cmd_suffix(t_node	*left)
// {
// 	if (token && is_io_redirect(token->type))
// 		return cmd_suffix(io_redirect(left));
// 	else if (token && is_word(token->type))
// 		return cmd_suffix(word(left));
// 	else
// 		return left;//epsilon
// }

// t_node	*io_redirect(t_node	*left)
// {
// 	t_node	*node;

// 	if (token->type == T_IN_REDIR || token->type == T_OUT_REDIR
// 		|| token->type == T_APPEND || token->type == T_HEREDOC)
// 	{
// 		node = ft_new_node(NULL, token->type);
// 		node -> left = left;
// 		node -> right = ft_new_node(token->value, 0);
// 		token = token -> next;
// 		return (node);
// 	}
// 	else
// 		return left;
// }

// t_node	*word(t_node *left)
// {
// 	t_node	*node;

// 	if (token && token->type == T_IDENTIFIER)
// 	{
// 		node = ft_new_node(token->value, token->type);
// 		token = token -> next;
// 		return (node);
// 	}
// 	else if (token && token->type == T_S_QUOTE)
// 	{
// 		node = ft_new_node(token->value, token->type);
// 		token = token -> next;
// 		return (node);
// 	}
// 	else if (token && token->type == T_D_QUOTE)
// 	{
// 		node = ft_new_node(token->value, token->type);
// 		token = token -> next;
// 		return (node);
// 	}
// 	else if (token && token->type == T_DOLLAR)
// 	{
// 		node = ft_new_node(token->value, token->type);
// 		token = token -> next;
// 		return (node);
// 	}
// 	else
// 		return (left);
// }

// int main()
// {
// 	// t_node	*tree;

// 	token = ft_tokenize();
// 	tree = command_line();
// 	if (!token)
// 	{
// 		printf("parsed successfully\n");
// 		// printf("%d %s\n", token->type, token->value);
// 	}
// 	else
// 	{
// 		printf("error parsing\n");
// 		// printf("%d %s\n", token->type, token->value);
// 	}
// }

char *str_test[] = 
{
	"T_IDENTIFIER",
	"T_LESS",
	"T_GREAT",
	"T_DLESS",
	"T_DGREAT",
	"T_PIPE",
	"T_O_PARENT",
	"T_C_PARENT",
	"T_AND",
	"T_OR"
};

int main()
{
	t_token *token;
	t_token *tmp;

	token = ft_tokenize();
	tmp = token;
	while(tmp)
	{
		printf("=======================================\n");
		printf("tmp is: %s\nits value: %s\n", str_test[tmp->type], tmp->value);
		printf("=======================================\n");
		tmp = tmp -> next;
	}
	ft_clear_token_list(&token);
}