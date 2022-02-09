CC = gcc

NAME = push_swap

LIBFTPATH = ./libft/

LIBFTNAME = libft.a

PRINTFPATH = ./printf/

PRINTFNAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

OBJ := $(*.o)

SRC = main.c

PARSING = ./parsing/check_arg.c

UTILS = ./sa.c ./pa.c ./ft_split_mod.c ./list_init.c ./list_init_utils.c ./operations.c ./operation_2.c ./check_val_list.c ./petit.c ./moyen.c ./grand.c ./grand2.c

all : $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
		make -C $(LIBFTPATH)
		make -C $(PRINTFPATH)
		mv $(LIBFTPATH)$(LIBFTNAME) $(LIBFTNAME)
		mv $(PRINTFPATH)$(PRINTFNAME) $(PRINTFNAME)
		${CC}  ${CFLAGS} ${SRC} $(PARSING) $(UTILS) $(PRINTFNAME) ${LIBFTNAME} -o ${NAME}

clean:
		rm -rf *.o

fclean: clean
		rm -f $(LIBFTNAME) $(PRINTFNAME) ${OBJS} $(NAME)

re: fclean all