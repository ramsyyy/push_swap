CC = gcc

NAME = push_swap

LIBFTPATH = ./libft/

LIBFTNAME = libft.a

PRINTFPATH = ./printf/

PRINTFNAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror 


OBJ := $(.c=.o)

SRC = ./src/main.c

PARSING = ./src/check_arg.c ./src/check_arg_utils.c

UTILS = ./src/sa.c ./src/pa.c ./src/ft_split_mod.c ./src/list_init.c ./src/list_init_utils.c ./src/operations.c ./src/operation_2.c ./src/check_val_list.c ./src/petit.c ./src/moyen.c ./src/grand.c ./src/grand_utils.c ./src/grand3.c 

all : $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
		make -C $(LIBFTPATH)
		make -C $(PRINTFPATH)
		mv $(LIBFTPATH)$(LIBFTNAME) $(LIBFTNAME)
		mv $(PRINTFPATH)$(PRINTFNAME) $(PRINTFNAME)
		${CC} ${CFLAGS} ${SRC} $(PARSING) $(UTILS) $(PRINTFNAME) ${LIBFTNAME} -o ${NAME}

clean:
		rm -rf *.o && make -C $(LIBFTPATH) clean && make -C $(PRINTFPATH) clean

fclean: clean
		rm -f $(LIBFTNAME) $(PRINTFNAME) ${OBJS} $(NAME) && make -C $(LIBFTPATH) fclean && make -C $(PRINTFPATH) fclean

re: fclean all