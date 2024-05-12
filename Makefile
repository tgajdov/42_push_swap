.PHONY: all clean fclean re libft fcleanlib testleaks test

#-L./Libft	: indique ou se trv la lib qu'il faut ajouter, le path
#-lft		: indique le nom de la lib, mais sans le préfixe lib-, le name
#-I	: indique ou se trv le .h de la lib, le path
#alternative à -I : noter dans le header local
#-C : permets de changer de dir avant d'exec la cmd

NAME = push_swap
CC = gcc
#CCFLAGS = -Wall -Wextra -Werror
LEAKS = leaks -atExit --
LDFLAGS = -L$(LIBFT_PATH) -lft
#Je n'ai pas encore compris a quoi sert le include vu que ça fonctionne sans
INCLUDES = #-I $(LIBFT_PATH)

RM = rm -rf
MKDIR = mkdir -p

LIBFT_PATH = ./lib/
SRC_DIR = src
OBJ_DIR = bin
BIN_DIR = bin

# Compiler flags to include library headers
#INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH)
# Compiler flags to link to libraries
#PATH_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH)

SRCS = $(wildcard ${SRC_DIR}/*.c)
OBJS = $(SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o)

#NUMBERS = 5121 7286 -6976 8639 -6938 -1573 3644 -5902 -5994 -6738 8458 -7007 6322 479 5496 -183 -8481 9886 3667 3005
#NUMBERS = -9989 -6091 -6085 -6061 -4914 -4225 -3569 -2023 -1899 -1760 -1203 -413 2357 4662 4872 4956 5236 5839 6853 7295
NUMBERS = -6 5 -7 1 0 7 -4 3 -2 6

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)
	@echo "$(GREEN) The Makefile of ${NAME} has been compiled!$(DEF_COLOR)"
	@echo "$(YELLOW)\n !Use this command in the folder root: ./${NAME} 53 24 87 1 5 98 ... 42\n$(DEF_COLOR)" 

$(NAME): $(OBJS) libft
	@echo "Creating ./$@"
	@$(CC) ${CCFLAGS} $(OBJS) $(INCLUDES) $(LDFLAGS) -o $(NAME)
	@echo "./$@ done"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKDIR} ${BIN_DIR}
	@${CC} ${CCFLAGS} $(INCLUDES) -c $< -o $@

libft:
	@echo "Creating $@"
	@make -C lib

test:
	@echo "Testing ${NAME}"
	@sleep 1
	@./${NAME} ${NUMBERS}

testleaks:
	@echo "Testing Leaks in ${NAME}"
	@sleep 1
	@${LEAKS} ./${NAME} ${NUMBERS}
#rajouter une regle ici pour hecker ces leaks

clean:
	@echo "Cleaning up ${NAME}"
	@${RM} ${OBJ_DIR}
	@echo "$(BLUE) ${NAME} Object files cleaned!$(DEF_COLOR)"

fcleanlib:
	@make fclean -C lib
	@echo "Cleaning up the lib"

fclean: clean
	@${RM} ${NAME}
	@echo "$(BLUE) ${NAME} Executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(BLUE) ${NAME} Cleaned and rebuilt everything!$(DEF_COLOR)"