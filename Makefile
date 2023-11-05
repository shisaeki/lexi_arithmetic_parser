# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 14:10:11 by shinsaeki         #+#    #+#              #
#    Updated: 2023/11/05 14:12:53 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc -o LexiArithmeticParser main.c lexer.c parser.c evaluator.c