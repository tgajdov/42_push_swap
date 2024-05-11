.PHONY: all clean fclean re libft fcleanlib checkleaks

#-L./Libft	: indique ou se trv la lib qu'il faut ajouter, le path
#-lft		: indique le nom de la lib, mais sans le préfixe lib-, le name
#-I	: indique ou se trv le .h de la lib, le path
#alternative à -I : noter dans le header local
#-C : permets de changer de dir avant d'exec la cmd

NAME = push_swap
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
LEAKS = leaks -atExit --
LDFLAGS = -L$(LIBFT_PATH) -lft
#Je n'ai pas encore compris a quoi sert le include vu que ça fonctionne sans
INCLUDES = #-I $(LIBFT_PATH)

RM = rm -rf
MKDIR = mkdir -p

LIBFT_PATH = /Users/toma/Desktop/42/Mes_projets/42_so_long/lib/

# Compiler flags to include library headers
#INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH)
# Compiler flags to link to libraries
#PATH_LIBS = -L$(LIBFT_PATH) -L$(MLX_PATH)

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:%.c=%.o)

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

%.o: %.c
	@${CC} ${CCFLAGS} $(INCLUDES) -c $< -o $@

libft:
	@echo "Creating $@"
	@make -C lib

checkleaks:
	@${LEAKS} ./${NAME}
#rajouter une regle ici pour hecker ces leaks

clean:
	@echo "Cleaning up ${NAME}"
	@${RM} ${OBJS}
	@echo "$(BLUE) ${NAME} Object files cleaned!$(DEF_COLOR)"

fcleanlib:
	@make fclean -C lib
	@echo "Cleaning up the lib"

fclean: clean
	@${RM} ${NAME}
	@echo "$(BLUE) ${NAME} Executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(BLUE) ${NAME} Cleaned and rebuilt everything!$(DEF_COLOR)"