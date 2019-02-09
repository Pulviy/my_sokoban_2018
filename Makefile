##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = 		gcc

RM = 		rm -rf

NAME = 		my_sokoban

SRC =		source/my_sokoban.c \
	        source/tools.c \
	    	source/init_struct.c \
	    	source/init_struct2.c \
	    	source/map_size.c \
	    	source/all_malloc.c \
	    	source/tools_malloc.c \
	    	source/game.c \
	    	source/win_loose_condition.c \
	    	source/moves_management.c \
	    	source/free_struct.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Iinclude

LDFLAGS = -lncurses

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) lib/my/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
