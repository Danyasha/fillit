# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btorp <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 21:39:04 by btorp             #+#    #+#              #
#    Updated: 2019/02/13 20:47:50 by btorp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g
LIB = ../../../libft/*.c
DLST = ../../dlst/*.c
VALIDATE = ../../validate/*.c
SRS = $(LIB) $(DLST) $(VALIDATE)
HEADERS = ../../../libft/libft.h ../../dlst/dlst.h ../../validate/validate.h ../backtraking.h
MAP = ../map_gen.c
MAP_TEST = map_gen_test.c
PLACE = ../tetra_place.c
PLACE_TEST = place_test.c
map:
	gcc $(MAP) $(MAP_TEST) $(FLAGS) $(SRS) -I $(HEADERS)
place:
	gcc $(PLACE) $(PLACE_TEST) $(MAP) $(FLAGS) $(SRS) -I $(HEADERS)