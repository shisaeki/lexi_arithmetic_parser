/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:30:40 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/11/04 14:47:46 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexi_arithmetic_parser.h"

int main(int argc, char **argv)
{
	t_token tokens[100];
	tokenizer(argv[1], tokens);

	printf("Tokens: ");
	for (int i = 0; tokens[i].type != TOKEN_EOF; i++)
	{
		switch (tokens[i].type)
		{
			case TOKEN_NUMBER:
				printf("%d ", tokens[i].value);
				break;
			case TOKEN_PLUS:
				printf("+ ");
				break;
			case TOKEN_MINUS:
				printf("- ");
				break;
			case TOKEN_MUL:
				printf("* ");
				break;
			case TOKEN_DIV:
				printf("/ ");
				break;
			case TOKEN_LPAREN:
				printf("( ");
				break;
			case TOKEN_RPAREN:
				printf(") ");
				break;
			case TOKEN_INVALID:
				printf("Invalid token\n");
				break;
			default:
				break;
		}
	}
}
