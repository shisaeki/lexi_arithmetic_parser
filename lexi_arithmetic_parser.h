/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_arithmetic_parser.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:38:45 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/11/04 14:45:08 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXI_ARITHMETIC_PARSER_H
# define LEXI_ARITHMETIC_PARSER_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum 
{
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MUL,
	TOKEN_DIV,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_EOF,
	TOKEN_INVALID
}	TokenType;

typedef struct	s_token
{
	TokenType	type;
	int			value;
}				t_token;

typedef enum
{
	AST_NUMBER,
	AST_BINARY_OP
}	ASTNodeType;

typedef struct		s_node
{
	ASTNodeType		type;
	union
	{
		int			value;
		struct
		{
			struct s_node	*left;
			struct s_node	*right;
			TokenType		op;
		}					bin_op;
	}				data;
}					t_node;

void tokenizer(const char *expr, t_token *tokens);

#endif