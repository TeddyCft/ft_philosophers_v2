#-variables------------------------------------------------------------#

MAKEFLAGS += --no-print-directory

QUIET = 	@

NAME = 		philo

MAIN = 		./src/main.c\

SOURCES =	$(MAIN)\
				
OBJ =		$(SOURCES:.c=.o)\

INCLUDES =	./includes

CC = $(QUIET) cc

FLAGS = -Wall -Wextra -Werror -g -pthread

#----------------------------------------------------------------------#

all : 			$(NAME)

#-compil---------------------------------------------------------------#

$(NAME) :		$(OBJ) 
				$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
				$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@


#-rules----------------------------------------------------------------#

clean :			
				$(QUIET) rm -f $(OBJ)
				
fclean : 		clean
				$(QUIET) rm -f $(NAME)
				
re : 			fclean all
