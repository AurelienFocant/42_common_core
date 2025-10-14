t_node  *parse_fact()
{
    t_node  *number;


    number->data = ft_atoi(str);

    return (number);
}

t_node *parse_term(str)
{
    t_node  *term

    term = parse_fact(str);
    if *
        parse_term(str);
    return (term);
}

t_node *parse_expr(char *str)
{
    t_node  *expr;

    expr = parse_term(str);
        if +
            parse_expr(str);

    return (expr);
}
