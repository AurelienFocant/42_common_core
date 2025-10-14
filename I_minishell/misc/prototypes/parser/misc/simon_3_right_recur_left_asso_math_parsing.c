#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_node t_node;

typedef struct s_number
{
    int data;
    t_node *next;
}   t_number;

typedef struct s_operator
{
    char operator;
    t_node *left;
    t_node *right;
}   t_operator;

typedef struct s_node
{
    t_operator  op;
    t_number    num;
}   t_node;

char *str_advance(char  **str)
{
    if (str)
    {
        printf("string before advance is %s\n", *str);
        (*str)++;
        printf("string after advance is %s\n", *str);
        return (*str);

    }
    else
        return (NULL);
}

t_node *create_num_node(char **str)
{
    t_node  *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);

    new_node->num.data = atoi(*str);
    new_node->num.next = NULL;

    return (new_node);
}

t_node *create_operator_node(t_node *left, t_node *right, char symbol)
{
    t_node  *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);

    new_node->op.operator = symbol;
    new_node->op.left = left;
    new_node->op.right = right;

    return (new_node);
}

t_node  *parse_fact(char **str)
{
    t_node  *number;

    number = create_num_node(str);
    //number->data = atoi(*str);
    str_advance(str);

    return (number);
}

t_node *parse_term(char **str)
{
    t_node  *left;
    t_node  *right;

    left = parse_fact(str);

    if (**str == '*')
    {   
        str_advance(str);
        right = parse_fact(str);
        left = create_operator_node(left, right, '*');
    }

    return (left);
}


t_node  *parse_expr(char **str)
{
    t_node  *left;
    t_node  *right;

    left = parse_term(str);

    if (**str == '+')
    {   
        str_advance(str);
        right = parse_term(str);
        left = create_operator_node(left, right, '+');
    }

    return(left);
}


t_node  *parser(char *str)
{
    t_node  *math_tree;

    math_tree = parse_expr(&str);

    return (math_tree);
}

int main(int ac, char **av)
{
    t_node  *ast;

    if (ac == 2)
    {
        ast = parser(av[1]);
        printf("first number in expression is %d\n", ast->num.data);
    }
    else
    {
        printf("usage !\n");
        return (1);
    }
    return (0);
}
