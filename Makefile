
.PHONY : all clean fclean re debug quiet

#-variables------------------------------------------------------------#

MAKEFLAGS += --no-print-directory
QUIET = 	

NAME = 		philo
INCLUDES =	./includes
CC = $(QUIET) cc
FLAGS = -Wall -Wextra -Werror -MMD -MP -g -pthread

FILES =		init \
			utils/ft_isdigit \
			utils/ft_strncmp \
			utils/ft_atoi \
			utils/ft_strlen


SRC_DIR		= 	src/
SRC_FILES	=	$(addsuffix .c, $(FILES))
SRC 		=	$(addprefix $(SRC_DIR), $(SRC_FILES))


MAIN		=	main.c
OBJ_DIR		= 	obj/
OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_MAIN	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_DIR)$(MAIN))


#----------------------------------------------------------------------#

all : 			$(NAME)

#-compil---------------------------------------------------------------#

$(NAME) :		$(OBJ_DIR) $(OBJ) $(OBJ_MAIN)
				$(CC) $(FLAGS) -I $(INCLUDES) $(OBJ) $(OBJ_MAIN) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ_DIR) :
				$(QUIET) mkdir -p $(OBJ_DIR)
				$(QUIET) mkdir -p $(OBJ_DIR)/utils


#-rules----------------------------------------------------------------#

clean :			
				$(QUIET) rm -rf $(OBJ_DIR)
				
fclean : 		clean
				$(QUIET) rm -f $(NAME)
				
re : 			fclean all
