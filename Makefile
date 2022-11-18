NAME		=	minitalk
SRV			= 	server
CLT			= 	client
SRV_B		=	server_bonus
CLT_B		=	client_bonus

#-------------------------------------#

LIBFT		=	./libft/libft.a
SRC_SRV		=	server.c
SRC_CLT		=	client.c
SRC_SRV_B	=	server_bonus.c
SRC_CLT_B	=	client_bonus.c
OBJ_SRV		=	$(SRC_SRV:.c=.o)
OBJ_CLT		=	$(SRC_CLT:.c=.o)
OBJ_SRV_B	=	$(SRC_SRV_B:.c=.o)
OBJ_CLT_B	=	$(SRC_CLT_B:.c=.o)

#-------------------------------------#

CFLAGS		=	-Wall -Wextra -Werror

all: $(LIBFT) $(SRV) $(CLT) bonus

$(LIBFT):
		make -C libft

$(NAME): all

$(SRV): $(OBJ_SRV)
		@gcc $(CFLAGS) $(OBJ_SRV) -Llibft -lft -o $(SRV)
		@echo "Server creado :D"

$(CLT): $(OBJ_CLT)
		@gcc $(CFLAGS) $(OBJ_CLT) -Llibft -lft -o $(CLT)
		@echo "Cliente creado :D"

$(SRV_B): $(OBJ_SRV_B)
		@gcc $(CFLAGS) $(OBJ_SRV_B) -Llibft -lft -o $(SRV_B)
		@echo "Server del bonus creado :D"

$(CLT_B): $(OBJ_CLT_B)
		@gcc $(CFLAGS) $(OBJ_CLT_B) -Llibft -lft -o $(CLT_B)
		@echo "Cliente del bonus creado :D"

bonus: $(CLT_B) $(SRV_B)

clean: 	
		@rm -rf $(OBJ_SRV) $(OBJ_CLT) $(OBJ_SRV_B) $(OBJ_CLT_B)
		@echo "Objetos eliminados :D"

fclean: clean
		@rm -rf $(SRV) $(CLT) $(SRV_B) $(CLT_B)
		@echo "Todo limpito :D"

re: fclean all

.PHONY: all clean fclean re
