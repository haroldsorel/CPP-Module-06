NAME = data
SRC =  main.cpp Data.cpp Serializer.cpp
OBJ = ${SRC:.cpp=.o}
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re