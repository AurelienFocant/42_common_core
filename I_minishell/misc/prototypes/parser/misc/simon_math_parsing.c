t_node  *parse_expr(char *str)
{
    t_node  *expr;

    expr = parse_term(str);
    return (expr);
}

t_node  *parser(char *str)
{
    t_node  *math_tree;
    t_node  *expr;
    t_node  *term;
    t_node  *factor;

    math_tree = parse_expr(str);

    return (math_tree);
}
