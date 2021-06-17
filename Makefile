
NAME = push_swap



# Files

EXT_LIB = libft.a

LIB_PATH = ./includes/libft/

SRC = ./srcs/main.c							\
	  ./srcs/command.c						\
	  ./srcs/in_out.c						\
	  ./srcs/stack/general.c				\
	  ./srcs/stack/adhoc.c					\
	  ./srcs/utils/pivot.c					\
	  ./srcs/utils/general.c				\
	  ./srcs/utils/status.c					\
	  ./srcs/sort/set_sort.c				\
	  ./srcs/sort/loaf.c					\
	  ./srcs/sort/small.c					\
	  ./srcs/sort/sort3to_a.c				\
	  ./srcs/sort/sort.c

OBJ = $(SRC:.c=.o)



# Compile

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all : $(NAME)

$(NAME) : libft $(OBJ)
		$(CC) $(CFLAGS) $(LIB_PATH)$(EXT_LIB) $(OBJ) -o $(NAME)



# Clean, Re

RM : rm -f

clean : clean_libft
		$(RM) $(OBJ)

fclean : clean fclean_libft
		$(RM) $(NAME)

re : fclean all




############### External library #################

libft :
		$(MAKE) -C $(LIB_PATH) all

clean_libft :
		$(MAKE) -C $(LIB_PATH) clean

fclean_libft :
		$(MAKE) -C $(LIB_PATH) fclean
