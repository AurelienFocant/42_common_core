#include "picoshell.h"

char* get_node_label(t_node *tree)
{
    char*   direction;
	static  char buffer[256];

    if (!tree)
        return "NULL";
    if (tree->type == CMD)
        return tree->data.cmd.string;
    if (tree->type == REDIR) {
        buffer[0] = '\0';
        if (tree->data.redir.type == IN)
            direction = "<";
        else if (tree->data.redir.type == OUT)
            direction = ">";
        else if (tree->data.redir.type == HEREDOC)
            direction = "<<";
        else if (tree->data.redir.type == APPEND)
            direction = ">>";
        else
            direction = "?";
        sprintf(buffer, sizeof(buffer), "REDIR(%s) %s", 
                direction, tree->data.redir.filename);
        return buffer;
    }
    if (tree->type == COND)
    {
        if (tree->data.cond.cond == AND)
            return "AND";
        else
            return "OR";
    }
    if (tree->type == PIPE)
        return "PIPE";
    return "UNKNOWN";
}

void write_node_connection(int fd, int parent_id, int child_id)
{
    dprintf(fd, "\tnode%d -> node%d;\n", parent_id, child_id);
}

void process_pipe_node(int fd, t_node *tree, int *node_id, int my_id)
{
    if (tree->data.pipe.left)
    {
        write_node_connection(fd, my_id, *node_id);
        ft_write_node(fd, tree->data.pipe.left, node_id);
    }
    if (tree->data.pipe.right)
    {
        write_node_connection(fd, my_id, *node_id);
        ft_write_node(fd, tree->data.pipe.right, node_id);
    }
}

void process_cmd_node(int fd, t_node *tree, int *node_id, int my_id)
{
    if (tree->data.cmd.next)
    {
        write_node_connection(fd, my_id, *node_id);
        ft_write_node(fd, tree->data.cmd.next, node_id);
    }
}

void process_redir_node(int fd, t_node *tree, int *node_id, int my_id)
{
    if (tree->data.redir.next)
    {
        write_node_connection(fd, my_id, *node_id);
        ft_write_node(fd, tree->data.redir.next, node_id);
    }
}

void process_cond_node(int fd, t_node *tree, int *node_id, int my_id)
{
    if (tree->data.cond.left)
    {
        write_node_connection(fd, my_id, *node_id);
        ft_write_node(fd, tree->data.cond.left, node_id);
    }
    if (tree->data.cond.right)
    {
        write_node_connection(fd, my_id, *node_id);
        ft_write_node(fd, tree->data.cond.right, node_id);
    }
}

void ft_write_node(int fd, t_node *tree, int *node_id)
{
    if (!tree)
        return;
    int my_id = *node_id;
    char *node_label = get_node_label(tree);

    dprintf(fd, "\tnode%d [label=\"%s\"];\n", my_id, node_label);
    (*node_id)++;
    if (tree->type == PIPE)
        process_pipe_node(fd, tree, node_id, my_id);
    else if (tree->type == COND)
        process_cond_node(fd, tree, node_id, my_id);
    else if (tree->type == CMD)
        process_cmd_node(fd, tree, node_id, my_id);
    else if (tree->type == REDIR)
        process_redir_node(fd, tree, node_id, my_id);
}

bool visualizer(t_node *tree)
{
    int fd = open("./misc/graph/tree.dot", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        printf("fd -1 could not open tree.dot :-(\n");
        return true;
    }

    int node_id = 0;
    dprintf(fd, "digraph AST {\n");
    ft_write_node(fd, tree, &node_id);
    dprintf(fd, "}\n");
    close(fd);

    return false;
}
