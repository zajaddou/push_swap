NAME= push_swap

CC= cc

CFLAG= -Wextra -Werror -Wall

MDR= push_swap.c ft_atoi.c ft_alloct.c

OBJ_M= $(MDR:%.c=%.o)

all: $(NAME) clean

$(NAME): LBFT $(OBJ_M) 
	$(CC) $(CFLAG) $(OBJ_M) -o $(NAME) LIBFT/libft.a

LBFT: LIBFT/libft.h
	@make -C LIBFT

%.o: %.c push_swap.h LIBFT/libft.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rif $(OBJ_M)
	clear

fclean: clean
	rm -rif $(NAME)
	make fclean -C LIBFT

re: fclean all LIBFT