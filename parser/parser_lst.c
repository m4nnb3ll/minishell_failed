#include "parser.h"

t_node	*ft_new_node(t_type type, char *value)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->type = type;
	return (new_node);
}
// if a problem occurs in the function above
// try allocating the space for the node_list