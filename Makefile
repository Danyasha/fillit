MAIN = srs/backtraking/*.c
VALIDATE = srs/validate/*.c
DLS = srs/dlst/*.c
LIB = libft/*.c
HEADERS = -I srs/backtraking/*.h srs/validate/*.h srs/dlst/*.h libft/*.h
NAME = fillit
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	gcc $(MAIN) $(VALIDATE) $(DLS) $(LIB) $(HEADERS) $(FLAGS)
	mv ./a.out fillit