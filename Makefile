NAME	=	minitalk
SRV	= server
CLT	= client
SRC_SRV	=	server.c utils.c
OBJ_SRV	=	$(SRC_SRV:.c=.o)
SRC_CLT	=	client.c utils.c
OBJ_CLT	=	$(SRC_CLT:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
CC		=	gcc

all: $(SRV) $(CLT)

$(NAME): all

$(SRV): $(OBJ_SRV)
		@$(CC) $(CFLAGS) $(OBJ_SRV) -o $(SRV)
		@echo "Server creado"

$(CLT): $(OBJ_CLT)
		@$(CC) $(CFLAGS) $(OBJ_CLT) -o $(CLT)
		@echo "Cliente creado"

clean: 	@$(RM) $(OBJ_SRV)
		@$(RM) $(OBJ_CLT)


fclean: clean
		@$(RM) $(SRV)
		@$(RM) $(CLT)

re: fclean all

.PHONY: all clean fclean re
