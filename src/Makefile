# Copyright (c) 2022 mmartini42 <mathmart@42lyon.fr>.

#
# Created by mathis martini on 09/10/2022.
#

NAME	=	containers

SRCS		=	main.cpp
OBJ		=	${SRC:.cpp=.o}

COMPILED_DIR	=	./compiled_sources
OBJS			=	$(addprefix $(COMPILED_DIR)/,$(SRCS:.cpp=.o))

CC				=	clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -Wshadow

all: $(NAME)

$(COMPILED_DIR):
	mkdir -p $(COMPILED_DIR)

$(COMPILED_DIR)/%.o:%.cpp	$(INCS)
	mkdir -p $(@D)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(COMPILED_DIR) $(INCS) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(COMPILED_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf result

re:	fclean all

testAll: testMap testStack testVector testTimeMap testTimeStack testTimeVector

testMap:
	./containers && diff ./result/map/MyMap.txt ./result/map/RealMap.txt

testTimeMap:
	@echo "\n\033[1;36mMine Map:"	&& time ./containers 1 1 && echo "\n\033[1;32mReal Map:" && time ./containers 0 1

testStack:
	./containers && diff ./result/stack/MyStack.txt ./result/stack/RealStack.txt

testTimeStack:
	@echo "\n\033[1;36mMine Stack:" && time ./containers 1 2 && echo "\n\033[1;32mReal Stack:" && time ./containers 0 2

testVector:
	./containers && diff ./result/vector/MyVector.txt ./result/vector/RealVector.txt

testTimeVector:
	@echo "\n\033[1;36mMine Vector:" && time ./containers 1 0 && echo "\n\033[1;32mReal Vector:" && time ./containers 0 0

.PHONY: all clean fclean re testTimeVector testVector testTimeStack testStack testTimeMap testMap
