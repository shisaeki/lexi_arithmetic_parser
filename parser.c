/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:56:37 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/11/05 13:54:58 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexi_arithmetic_parser.h"

t_node *create_number_node(int value)
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->type = AST_NUMBER;
    node->data.value = value;
    return (node);
}

t_node *create_binary_node(t_node *left, t_node *right, TokenType op)
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->type = AST_BINARY_OP;
    node->data.bin_op.left = left;
    node->data.bin_op.right = right;
    node->data.bin_op.op = op;
    return (node);
}

t_token get_next_token(int *index, t_token *tokens)
{
    *index += 1;
    return (tokens[*index - 1]);
}

t_token get_current_token(int *index, t_token *tokens)
{
    return (tokens[*index]);
}

t_node *expression(int *index, t_token *tokens)
{
    t_node *node = term(index, tokens);
    t_token token = get_current_token(index, tokens);
    while (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS)
    {
        get_next_token(index, tokens);
        t_node *right = term(index, tokens);
        node = create_binary_node(node, right, token.type);
        token = get_current_token(index, tokens);
    }
    return (node);
}

t_node *term(int *index, t_token *tokens)
{
    t_node *node = factor(index, tokens);
    t_token token = get_current_token(index, tokens);
    while (token.type == TOKEN_MUL || token.type == TOKEN_DIV)
    {
        get_next_token(index, tokens);
        t_node *right = factor(index, tokens);
        node = create_binary_node(node, right, token.type);
        token = get_current_token(index, tokens);
    }
    return (node);
}

t_node *factor(int *index, t_token *tokens)
{
    t_token token = get_next_token(index, tokens);
    if (token.type == TOKEN_NUMBER)
        return (create_number_node(token.value));
    else if (token.type == TOKEN_LPAREN)
    {
        t_node *node = expression(index, tokens);
        token = get_next_token(index, tokens);
        if (token.type != TOKEN_RPAREN)
        {
            printf("Syntax error: expected ')', got %d\n", token.type);
            exit(-1);
        }
        return (node);
    }
    else
    {
        printf("Syntax error: expected number or '(', got %d\n", token.type);
        exit(-1);
    }
}

t_node *parse(int *index, t_token *tokens)
{
    return (expression(index, tokens));
}