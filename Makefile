CC			= clang
CFLAGS	=	-Wall -Werror -Wextra
NAME		=	ssa_tool
OBJ			= ./main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -g

clean:
	rm -f $(OBJ) $(NAME)

run: $(NAME)
	@./$(NAME)
