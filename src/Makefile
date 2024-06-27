# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 07:47:48 by rbutzke           #+#    #+#              #
#    Updated: 2024/06/27 12:01:20 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------------------------------------------------------------------------------
# Static library
NAME		:= philo.a

#-----------------------------------------------------------------------------------------
# Compiler and flags
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g3
O_FLAGS		:= -c

#-----------------------------------------------------------------------------------------
# Command to clean up files
CMD_CLEAN	:= rm -Rf

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES	:= -I ../includes

#-----------------------------------------------------------------------------------------
# Source files
FILE		:=  00_main.c\
				01_valid_arg.c\
				02_set_args.c\
				03_get_time.c\
				04_atoui.c\
				05_init_lst.c\
				06_add_back.c\
				07_del_lst.c\
				08_init_tread.c\
				09_routine.c\
				09.1_eat.c\
				09.2_sleep.c\
				09.3_ft_think.c\
				09.4_msg.c\
				09.5_mutex.un_lock.c\
				10_monitor.c\
				11_destroy.c

#-----------------------------------------------------------------------------------------
NUM_FILES	:= $(words $(FILE))

#-----------------------------------------------------------------------------------------
# Directory for object files
OBJS		:= objs
O_FILE		:= $(FILE:%.c=$(OBJS)/%.o)

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
	@mkdir -p $(OBJS)
	@$(CC) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@
	@$(eval COUNT := $(shell echo $$(($(COUNT)+1))))
	@printf "Creating binaries from lib functions   [%s]\r" $(shell echo "$$(($(COUNT) * 100 / $(NUM_FILES)))%")
	@sleep 0.3

#-----------------------------------------------------------------------------------------
# Rule to clean
clean:
	$(CMD_CLEAN) $(OBJS) $(NAME)