
NAME = push_swap



# Files
EXT_LIB = ./srcs/libft/libft.a

SRC = ./srcs/main.c

OBJ = $(SRC:.c=.o)



# Compile
CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) libft
		$(CC) $(CFLAGS) $(EXT_LIB) $(OBJ) -o $(NAME)



# Clean, Re
RM : rm -f

clean : clean_libft
		$(RM) $(OBJ)

fclean : fclean_libft
		$(RM) $(NAME)

re : fclean all


############### External library #################

libft : 
		$(MAKE) -C ./srcs/libft all bonus

clean_libft :
		$(MAKE) -C ./srcs/libft clean

fclean_libft :
		$(MAKE) -C ./srcs/libft fclean
