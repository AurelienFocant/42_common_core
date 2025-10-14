/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_node
{
	int	type;
	char	*value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;


typedef enum
{
	PIPE,
	CMD,
	REDIR
}	node_type;

bool	ft_transform_ll_to_dotfile(t_node *);
void ft_write_node(int fd, t_node *tree, int *node_id);

int	main()
{
	t_node	*pipe;
	t_node	*cmd1;
	t_node	*redir;
	t_node	*cmd2;
	t_node	*tree;
	

	pipe = malloc(sizeof(t_node));
	cmd1 = malloc(sizeof(t_node));
	redir = malloc(sizeof(t_node));
	cmd2 = malloc(sizeof(t_node));

	pipe->type = PIPE;
	pipe->value = NULL;
	pipe->left = cmd1;
	pipe->right = cmd2;

	cmd1->type = CMD;
	cmd1->value = "echo hello";
	cmd1->left = NULL;
	cmd1->right = NULL;

	cmd2->type = CMD;
	cmd2->value = "cat -e";
	cmd2->left = redir;
	cmd2->right = NULL;

	redir->type = REDIR;
	redir->value = "> outfile";
	redir->left = NULL;
	redir->right = NULL;

	tree = pipe;


	if (ft_transform_ll_to_dotfile(tree))
		return (0);
	else
		return (1);
}

bool	ft_transform_ll_to_dotfile(t_node *tree)
{
	int	fd;
	int	node_id = 0;

	fd = open("tree.dot", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	dprintf(fd, "digraph AST {\n");
	ft_write_node(fd, tree, &node_id);
	dprintf(fd, "}\n");
	close(fd);
	return (0);
}

void ft_write_node(int fd, t_node *tree, int *node_id)
{
	char		*node_label;
	int my_id = *node_id;

	if (!tree)
		return ;
	if (tree->value == NULL)
		node_label = "PIPE";
	else
		node_label = tree->value;
	dprintf(fd, "\tnode%d [label=\"%s\"];\n", my_id, node_label);
	(*node_id)++;
	if (tree->left)
	{
		dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
		ft_write_node(fd, tree->left, node_id);
	}
	if (tree->right)
	{
		dprintf(fd, "\tnode%d -> node%d;\n", my_id, *node_id);
		ft_write_node(fd, tree->right, node_id);
	}
}
*/
