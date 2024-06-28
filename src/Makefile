# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:48 by rbutzke           #+#    #+#              #
#    Updated: 2024/06/28 08:59:21 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME			:= philo.a

#-----------------------------------------------------------------------------------------
# Compiler and flags
CFLAGS			:= -Wall -Werror -Wextra -g3 -MMD
CC				:= cc
O_FLAGS			:= -c

#-----------------------------------------------------------------------------------------
# Command to clean up files
CMD_CLEAN		:= rm -Rf

#-----------------------------------------------------------------------------------------
# DIRECTORY and Header file
UTILS			:= utils/
ARGS			:= args/
LIST			:= lst/
THREAD			:= thread/
ROUTINE			:= routine/

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES		:= -I ../includes -I $(UTILS) -I $(THREAD)\
				-I $(LIST) -I $(ARGS) -I $(ROUTINE)

#-----------------------------------------------------------------------------------------
# Source files
FILE_UTILS		:= get_time.c atol.c
FILE_ARGS		:= valid_arg.c set_args.c
FILE_LIST		:= init_lst.c add_back.c del_lst.c
FILE_THREAD		:= init_tread.c destroy.c mutex.un_lock.c
FILE_ROUTINE	:= routine.c eat.c sleep.c ft_think.c output.c monitor.c

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES			:= $(addprefix $(UTILS), $(FILE_UTILS))\
					$(addprefix $(ARGS), $(FILE_ARGS))\
					$(addprefix $(LIST), $(FILE_LIST))\
					$(addprefix $(THREAD), $(FILE_THREAD))\
					$(addprefix $(ROUTINE), $(FILE_ROUTINE))\
					main.c

#-----------------------------------------------------------------------------------------
NUM_FILES	:= $(words $(SRC_FILES))

#-----------------------------------------------------------------------------------------
# Directory for object files
OBJS		:= objs
O_FILE		:= $(SRC_FILES:%.c=$(OBJS)/%.o)
DEP_FILES   := $(O_FILE:%.o=%.d)

#-----------------------------------------------------------------------------------------
# Default rule to create the static library
all: $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to create the static library
$(NAME): $(O_FILE)
	@ar -rc $(NAME) $(O_FILE)
	@echo ""

#-----------------------------------------------------------------------------------------
# Rule to compile source files into object files
$(OBJS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@printf "Creating the program binaries   [%s]\r" $(shell echo "$$(($(COUNT) * 100 / $(NUM_FILES)))%")

#-----------------------------------------------------------------------------------------
# Include dependency files
-include $(DEP_FILES)

#-----------------------------------------------------------------------------------------
# Rule to clean
clean:
	@$(CMD_CLEAN) $(OBJS) $(NAME)