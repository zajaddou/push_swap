NAME = push_swap

CC = cc
CFLAG = -Wextra -Werror -Wall

MDR = push_swap.c src/parsing.c src/stack.c src/extra.c src/moves.c src/sort.c src/bigsort.c src/check.c src/more.c
OBJ_M = $(MDR:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_M) LIBFT/libft.a
	$(CC) $(CFLAG) $(OBJ_M) -o $(NAME) LIBFT/libft.a

LIBFT/libft.a: 
	@make -C LIBFT

%.o: %.c push_swap.h LIBFT/libft.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
	@rm -rf $(OBJ_M)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C LIBFT

re: fclean all
