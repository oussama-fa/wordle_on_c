NAME = Wordel

CC = cc

CFLAG = #-g3 -fsanitize=address

RM = rm -rf

HEADER = wordle.h

SRC = wordle.c get_next_line_utils.c get_next_line.c ft_split.c \
	database.c parsing.c utils.c garbage.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAG) $(OBJ) -o $(NAME)

%.o:%.c $(INC)
		$(CC) $(CFLAG) -c $< -o $@

clean:
		$(RM) $(OBJ) 

fclean: clean
		$(RM) $(NAME) 

re: fclean all

.PHONY: clea