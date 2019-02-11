# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btorp <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 16:47:44 by btorp             #+#    #+#              #
#    Updated: 2019/02/11 16:11:57 by btorp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKTETRA = ../ft_check_tetra.c
LIB = ../../../libft/*.c
TETRA = test_check_tetra.c
DLST = ../../dlst/*.c
MAIN = ft_main_test.c
SRS = ../*.c
HEADERS = ../dlst/dlst.h ../../../libft/libft.h ../validate.h
tetra:
	gcc $(CHECKTETRA) $(LIB) $(TETRA) -I $(HEADERS) -g
main:
	gcc $(MAIN) $(SRS) $(DLST) $(LIB) -I $(HEADERS) -g