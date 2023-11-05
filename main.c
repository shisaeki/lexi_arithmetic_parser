/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:30:40 by shinsaeki         #+#    #+#             */
/*   Updated: 2023/11/05 14:06:45 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexi_arithmetic_parser.h"

int main(int argc, char **argv)
{
	t_token tokens[100];
	int index = 0;
	t_node *node_root;
	tokenizer(argv[1], tokens);
	node_root = parse(&index, tokens);
	printf("%d\n", evaluate(node_root));
}
