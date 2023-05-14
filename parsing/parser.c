/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:55:17 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/14 23:48:05 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "parser.h"

char	*types[] = 
{
	"T_IDENTIFIER",
	"<",
	">",
	"<<",
	">>",
	"|",
	"OP",
	"CP",
	"&&",
	"||"
};


t_token *token;

void	get_next_token();
bool	is_binop(t_type type);
int		prec(t_type type);
t_node	*term();
t_node	*expression(int min_prec);

void	get_next_token()
{
	token = token -> next;
}

bool	is_binop(t_type type)
{
	if (type == T_PIPE || type == T_AND || type == T_OR )
		return (true);
	return (false);
}

bool	is_redir(t_type type)
{
	if (type == T_LESS || type == T_GREAT
		|| type == T_DLESS || type == T_DGREAT)
		return (true);
	return (false);
}

int	prec(t_type type)
{
	if (type == T_OR)
		return (0);
	if (type == T_AND)
		return (1);
	return (2);
}

bool	ft_get_io_list(t_io_node **io_list)
{
	t_type		redir_type;
	t_io_node	*tmp_io_node;

	while (token && is_redir(token->type))
	{
		redir_type = token->type;
		get_next_token();
		if (token->type != T_IDENTIFIER)
			return (false);//ERROR
		tmp_io_node = ft_new_io_node(redir_type, token->value);
		if (!tmp_io_node)
			exit(1);
		ft_append_io_node(io_list, tmp_io_node);
		get_next_token();
	}
	return (1);
}

void	ft_join_args(char **args)
{
	char	*to_free;

	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		exit(1);
	while (token && token -> type == T_IDENTIFIER)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, token -> value, ' ');
		if (!args)
			exit(1);
		free(to_free);
		get_next_token();
	}
}

t_node	*get_simple_cmd()
{
	t_node	*node;

	node = ft_new_node(T_CMD);
	while (token
		&& (token->type == T_IDENTIFIER || is_redir(token->type)))
	{
		if (token->type == T_IDENTIFIER)
			ft_join_args(&(node -> args));
		else if (is_redir(token->type))
		{
			if (!ft_get_io_list(&(node->io_list)))
			{
				printf("Syntax error near: %s\n", types[token->type]);
				exit(1);
			}
		}
	}
	return (node);
}

t_node	*term()
{
	t_node	*node;

	if (is_binop(token->type))
	{
		printf("Syntax error near: %s\n", types[token->type]);
		exit(1);//tmp
	}
	else if (token->type == T_O_PARENT)
	{
		get_next_token();
		node = expression(0);
		if (!token || token->type != T_C_PARENT)
		{
			printf("Unclosed parenthesis!\n");
			exit(1);//tmp
		}
		get_next_token();
		return (node);
	}
	else
		return get_simple_cmd();
}

t_node	*combine(t_type op, t_node *left, t_node *right)
{
	t_node	*node;

	node = ft_new_node(op);
	node -> left = left;
	node -> right = right;
	return (node);
}

t_node	*expression(int min_prec)
{
	t_node	*left;
	t_node	*right;
	int		n_prec;
	t_type	op;

	left = term();
	while (token && is_binop(token->type) && prec(token->type) >= min_prec)
	{
		op = token->type;
		get_next_token();
		n_prec = prec(op) + 1;
		right = expression(n_prec);
		left = combine(op, left, right);
	}
	return (left);
}

t_node	*parse_command()
{
	return expression(0);
	if (!token)
		printf("unexpected end of file!!!\n");
}

void	print_tree(t_node *node)
{
	t_io_node	*tmp_io_node;

	if (node -> type != T_CMD)
	{
		printf("(");
		if (node -> left)
			print_tree(node -> left);
		if (is_binop(node->type))
			printf(" ");
		printf("%s", types[node->type]);
		if (is_binop(node->type))
			printf(" ");
		if (node -> right)
			print_tree(node -> right);
		printf(")");
	}
	else
	{
		printf("%s ", node->args);
		tmp_io_node = node -> io_list;
		while (tmp_io_node)
		{
			printf("%s%s", types[tmp_io_node->type], tmp_io_node->value);
			tmp_io_node = tmp_io_node -> next;
			if (tmp_io_node)
				printf(" ");
		}
	}
}

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("%s\n", types[tokens->type]);
		tokens = tokens -> next;
	}
}

int main()
{
	t_node	*tree;

	while (1)
	{
		token = ft_tokenize();
		if (!token)
			continue ;// To be changed later
		tree = parse_command();
		print_tree(tree);
		printf("\n");
	}
	// printf("Parsed successfully!\n");
}
