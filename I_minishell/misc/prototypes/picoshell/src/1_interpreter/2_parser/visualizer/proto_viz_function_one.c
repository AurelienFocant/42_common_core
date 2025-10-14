/*
#include "picoshell.h"
#include "parser.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void	ft_write_node(int fd, t_node *tree, int *node_id)
{
	char	*node_label;
	int		my_id;

	if (!tree)
		return ;

	my_id = *node_id;

	if (tree->type == CMD)
		node_label = tree->data.cmd.string;
	else if (tree->type == REDIR)
		node_label = tree->data.redir.filename;
	else if (tree->type == COND)
	{
		if (tree->data.cond.cond == AND)
			node_label = "AND";
		else
			node_label = "OR";
	}
	else if (tree->type == PIPE)
		node_label = "PIPE" ;
	else
		node_label = "UNKNOWN" ;

	dprintf(fd, "\tnode%d [label=\"%s\"];\n", my_id, node_label);

	(*node_id)++;

	if (tree->type == PIPE)
	{
		if (tree->data.pipe.left)
		{
			dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
			ft_write_node(fd, tree->data.pipe.left, node_id);
		}
		if (tree->data.pipe.right)
		{
			dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
			ft_write_node(fd, tree->data.pipe.right, node_id);
		}
	}
	else if (tree->type == COND)
	{
		if (tree->data.cond.left)
		{
			dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
			ft_write_node(fd, tree->data.cond.left, node_id);
		}
		if (tree->data.cond.right)
		{
			dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
			ft_write_node(fd, tree->data.cond.right, node_id);
		}
	}
	else if (tree->type == CMD)
	{
		if (tree->data.cmd.next)
		{
			dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
			ft_write_node(fd, tree->data.cmd.next, node_id);
		}
	}
	else if (tree->type == REDIR)
	{
		if (tree->data.redir.next)
		{
			dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
			ft_write_node(fd, tree->data.redir.next, node_id);
		}
	}

}

bool	visualizer(t_node *tree)
{
	int	fd;
	int	node_id;

	node_id = 0;

	fd = open("./misc/graph/tree.dot", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("fd -1 could not open tree.dot :-(\n)");
		return (1);
	}
	dprintf(fd, "digraph AST {\n");
	ft_write_node(fd, tree, &node_id);
	dprintf(fd, "}\n");
	close(fd);
	return (0);
}
*/
