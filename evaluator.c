/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:01:04 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/11/05 14:12:47 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexi_arithmetic_parser.h"

int evaluate(t_node *node)
{
	switch (node -> type)
	{
	case AST_NUMBER:
		return (node->data.value);
		break;
	case AST_BINARY_OP:
		switch (node->data.bin_op.op)
		{
			case TOKEN_PLUS:
				return (evaluate(node->data.bin_op.left) + evaluate(node->data.bin_op.right));
				break;
			case TOKEN_MINUS:
				return (evaluate(node->data.bin_op.left) - evaluate(node->data.bin_op.right));
				break;
			case TOKEN_MUL:
				return (evaluate(node->data.bin_op.left) * evaluate(node->data.bin_op.right));
				break;
			case TOKEN_DIV:
				return (evaluate(node->data.bin_op.left) / evaluate(node->data.bin_op.right));
				break;
			default:
				exit(-1);
		}
	default:
		exit(-1);
	}
}