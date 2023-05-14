#include "tokenizer.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	t_node	*root;

	root = ft_new_node(T_PIPE);
	root -> left = ft_new_cmd_node();
	root -> right = ft_new_cmd_node();

	((t_cmd_node*)(root -> left)) -> io_list = ft_new_io_node(T_LESS, "INFILE");
	((t_cmd_node*)(root -> left)) -> args = ft_split("echo hello world", ' ');
	((t_cmd_node*)(root -> right)) -> io_list = ft_new_io_node(T_GREAT, "OUTFILE");
	((t_cmd_node*)(root -> right)) -> args = ft_split("!echo !hello !world", ' ');
	ft_clear_tree((void **)&root);
}