# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:04 by rbutzke           #+#    #+#              #
#    Updated: 2024/06/27 13:03:29 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------------------------------------------------------------------------------	
# Program name
NAME                := philo

#-----------------------------------------------------------------------------------------	
# Path to the static library
BINARY              := ./src/philo.a

#-----------------------------------------------------------------------------------------
# Compiler and flags
CC                  := cc
CFLAGS              := -Wall -Werror -Wextra -g3
OFLAGS              := -c

#-----------------------------------------------------------------------------------------	
# clean comand and flag
CLEAN_CMD				:= rm -Rf

#-----------------------------------------------------------------------------------------	
# Paths to the subdirectories containing source files
PATH_MAKE_OBJ			:= src

#-----------------------------------------------------------------------------------------	
# Default rule to create the executable
all: $(NAME)

#-----------------------------------------------------------------------------------------	
# Rule to link the static library and create the executable
$(NAME):
	@$(CC) $(BINARY) -o $(NAME) -pthread
	@printf "\nExecutable %s created successfully\n" $(NAME)

#-----------------------------------------------------------------------------------------	
# Rule to create the static library by compiling source files in subdirectories
$(NAME): object

#-----------------------------------------------------------------------------------------	
# Rule ti create object
object:
	@$(MAKE) -C $(PATH_MAKE_OBJ) --no-print-directory

object_clean:
	@$(MAKE) -C $(PATH_MAKE_OBJ) clean --no-print-directory

#-----------------------------------------------------------------------------------------
# Rule to clean
clean: object_clean
	$(CLEAN_CMD) $(BINARY)

fclean: clean
	$(CLEAN_CMD) $(NAME)

re: fclean all

.PHONY: all list main main_clean main_fclean list_clean list_fclean clean fclean re