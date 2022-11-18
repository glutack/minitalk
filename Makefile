NAME	=	minitalk
SRV		= 	server
CLT		= 	client
LIBFT	=	./libft/libft.a
SRC_SRV	=	server.c
OBJ_SRV	=	$(SRC_SRV:.c=.o)
SRC_CLT	=	client.c
OBJ_CLT	=	$(SRC_CLT:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror

all: $(LIBFT) $(SRV) $(CLT)

$(LIBFT):
		make -C libft

$(NAME): all

$(SRV): $(OBJ_SRV)
		@gcc $(CFLAGS) $(OBJ_SRV) -Llibft -lft -o $(SRV)
		@echo "Server creado :D"

$(CLT): $(OBJ_CLT)
		@gcc $(CFLAGS) $(OBJ_CLT) -Llibft -lft -o $(CLT)
		@echo "Cliente creado :D"

clean: 	
		@rm -rf $(OBJ_SRV) $(OBJ_CLT)
		@echo "Objetos eliminados :D"

fclean: clean
		@rm -rf $(SRV) $(CLT)
		@echo "Todo limpito :D"

re: fclean all

.PHONY: all clean fclean re
