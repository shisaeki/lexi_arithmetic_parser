/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:30:40 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/10/21 11:45:45 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

typedef enum
{
	TOKEN_NUM,
	TOKEN_OP,
	TOKEN_END,
	TOKEN_ERR,
	TOKEN_LPAREN,
	TOKEN_RPAREN
}	TokenType;

typedef struct	s_token
{
	TokenType   type;
	union
	{
		int	 value;
		char op;
	}	data;
}               t_token;

t_token	get_token(const char **expr)
{
	while (isspace(**expr))
		(*expr)++;
	if (isdigit(**expr))
	{
		int value = 0;
		while (isdigit(**expr))
		{
			value = value * 10 + (**expr - '0');
			(*expr)++;
		}
		return (t_token){TOKEN_NUM, .data.value = value};
	}

	switch (**expr)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return (t_token){TOKEN_OP, .data.op = *((*expr)++)};
		case '(':
			(*expr)++;
			return (t_token){TOKEN_LPAREN};
		case ')':
			(*expr)++;
			return (t_token){TOKEN_RPAREN};
		case '\0':
			return (t_token){TOKEN_END};
		default:
			return (t_token){TOKEN_ERR};
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <expr>\n", argv[0]);
		return (1);
	}

	const char *expr = argv[1];
	t_token token = get_token(&expr);
	if (token.type == TOKEN_ERR)
	{
		printf("Invalid token found: %c\n", *expr);
		return (1);
	}

	while (token.type != TOKEN_END)
	{
		switch (token.type)
		{
			case TOKEN_NUM:
				printf("%d\n", token.data.value);
				break;
			case TOKEN_OP:
				printf("%c\n", token.data.op);
				break;
			case TOKEN_LPAREN:
				printf("(\n");
				break;
			case TOKEN_RPAREN:
				printf(")\n");
				break;
			default:
				break;
		}
		token = get_token(&expr);
	}
	return (0);
}