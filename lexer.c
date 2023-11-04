/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:44:10 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/11/04 14:51:32 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexi_arithmetic_parser.h"

void tokenizer(const char *expr, t_token *tokens)
{
    int i = 0;
    int tokenIndex = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++;
        } else if (isdigit(expr[i])) {
            char *endptr;
            tokens[tokenIndex].type = TOKEN_NUMBER;
            tokens[tokenIndex].value = strtol(&expr[i], &endptr, 10);
            i = endptr - expr;
            tokenIndex++;
        } else {
            switch (expr[i]) {
                case '+': tokens[tokenIndex].type = TOKEN_PLUS; break;
                case '-': tokens[tokenIndex].type = TOKEN_MINUS; break;
                case '*': tokens[tokenIndex].type = TOKEN_MUL; break;
                case '/': tokens[tokenIndex].type = TOKEN_DIV; break;
                case '(': tokens[tokenIndex].type = TOKEN_LPAREN; break;
                case ')': tokens[tokenIndex].type = TOKEN_RPAREN; break;
                default: tokens[tokenIndex].type = TOKEN_INVALID; break;
            }
            i++;
            tokenIndex++;
        }
    }
    tokens[tokenIndex].type = TOKEN_EOF;
}
