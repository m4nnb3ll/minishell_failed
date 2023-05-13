/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:55:17 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/13 18:11:31 by abelayad         ###   ########.fr       */
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
t_node	*tree = NULL;



void	get_next_token();
bool	is_unaop(t_type type);
bool	is_binop(t_type type);
int		prec(t_type type);
t_node	*term();
t_node	*expression(int min_prec);

void	get_next_token()
{
	token = token -> next;
}

bool	is_unaop(t_type type)
{
	if (type == T_LESS || type == T_GREAT || type == T_DLESS
		|| type == T_DGREAT)
		return (true);
	return (false);
}

bool	is_binop(t_type type)
{
	if (type == T_LESS || type == T_GREAT || type == T_DLESS
		|| type == T_DGREAT || type == T_PIPE || type == T_AND 
		|| type == T_OR )
		return (true);
	return (false);
}

int	prec(t_type type)
{
	if (type == T_OR)
		return (0);
	if (type == T_AND)
		return (1);
	return (3);
}

t_node	*term()
{
	t_node	*node;
	t_type	op;

	// printf("<TERM>\ntoken->type: %s\nis_unaop: %d\n", types[token->type], is_unaop(token->type));
	if (is_unaop(token->type))
	{
		op = token->type;
		get_next_token();
		if (token->type != T_IDENTIFIER)
			printf("Error near %d!\n", token->type);
		node = ft_new_node(op, NULL);
		node -> right = ft_new_node(0, token->value);
		get_next_token();
		return node;
	}
	else if (token->type == '(')
	{
		get_next_token();
		node = expression(0);
		if (token->type != ')')
			printf("Unclosed parenthesis!\n");
		get_next_token();
		return (node);
	}
	else
	{
		node = ft_new_node(token->type, token->value);
		// printf("token->type is: %s\ntoken->value is: %s\n", types[token->type], token->value);
		get_next_token();
		return (node);
	}
}

t_node	*combine(t_type op, t_node *left, t_node *right)
{
	t_node	*node;

	node = ft_new_node(op, NULL);
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

	// write(1, "pass0\n", 6);
	left = term();
	while (token && is_binop(token->type) && prec(token->type) >= min_prec)
	{
		op = token->type;
		get_next_token();
		// printf("i enter the while\n");
		// write(1, "pass1\n", 6);
		n_prec = prec(op) + 1;
		// write(1, "pass2\n", 6);
		// write(1, "pass3\n", 6);
		right= expression(n_prec);
		// write(1, "pass4\n", 6);
		left = combine(op, left, right);
		// write(1, "pass5\n", 6);
	}
	return (left);
}

t_node	*parse_command()
{
	return expression(0);
	if (!token)
		printf("unexpected end of file!!!\n");
}

void	print_space(int	size)
{
	while(size)
	{
		printf("-");
		size--;
	}
}

// void	print_tree(t_node *node, int space_size)
// {
// 	if (node -> type)
// 	{
// 		print_space(space_size);
// 		printf("type: %s", types[node -> type]);
// 		if (node -> value)
// 			printf(" ");
// 		else
// 			printf("\n");
// 	}
// 	if (node -> value)
// 	{
// 		print_space(space_size);
// 		printf("value: %s\n", node -> value);
// 	}
// 	if (node -> left)
// 	{
// 		print_space(space_size + 1);
// 		printf("left:");
// 		print_tree(node -> left, space_size + 2);
// 	}
// 	if (node -> right)
// 	{
// 		print_space(space_size + 1);
// 		printf("right:");
// 		print_tree(node -> right, space_size + 2);
// 	}
// }

void	print_tree(t_node *node)
{
	if (node -> type)
	{
		printf("(");
		if (node -> left)
			print_tree(node -> left);
		if (is_binop(node->type) || is_unaop(node->type))
			printf(" ");
		printf("%s", types[node->type]);
		if (is_binop(node->type) || is_unaop(node->type))
			printf(" ");
		if (node -> right)
			print_tree(node -> right);
		printf(")");
	}
	else if (node -> value)
		printf("%s", node -> value);
}

int main()
{
	t_node	*tree;

	token = ft_tokenize();
	tree = parse_command();
	// printf("first node is: %s %s\n", types[tree->type], tree->value);
	// if (tree -> left)
	// 	printf("left node is: %s\n", types[tree->left->type]);
	// if (tree -> right)
	// 	printf("right node is: %s\n", types[tree->right->type]);
	print_tree(tree);
	printf("\n");
}
