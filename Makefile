CC			= clang
CFLAGS	=	-Wall -Werror -Wextra
NAME		=	ssa_tool
OBJ			= ./main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(NAME)

run: $(NAME)
	@./$(NAME)
