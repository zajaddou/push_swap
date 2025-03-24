
NAME= push_swap

CC= cc

CFLAG= -Wextra -Werror -Wall

MDR= push_swap.c src/parsing.c src/stack.c src/extra.c src/moves.c src/sort.c src/bigsort.c src/check.c src/more.c

OBJ_M= $(MDR:%.c=%.o)

all: $(NAME) clean

$(NAME): LBFT $(OBJ_M) 
	$(CC) $(CFLAG) $(OBJ_M) -o $(NAME) LIBFT/libft.a

LBFT: LIBFT/libft.h
	@make -C LIBFT

%.o: %.c push_swap.h LIBFT/libft.h
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rif $(OBJ_M)
	clear

fclean: clean
	rm -rif $(NAME)
	make fclean -C LIBFT
	clear

push: fclean
	@git add .
	@git commit -m "update"
	@git push
	clear

test: all
	clear && cd tester && python3 tester.py

re: fclean all
	clear