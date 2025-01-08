# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 14:44:14 by toferrei          #+#    #+#              #
#    Updated: 2025/01/08 12:36:35 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =	philo

PRINTF		=	Ft_Printf/
SRC			=	Sources/
OBJ_DIR		=	Objects/
PRINTF_A	=	$(PRINTF)libftprintf.a

# Sources and Objects
SOURCES		=	$(SRC)dinner.c \
				$(SRC)getter_setter.c \
				$(SRC)init.c \
				$(SRC)main.c \
				$(SRC)monitoring.c \
				$(SRC)parsing.c \
				$(SRC)safe_functions.c \
				$(SRC)synchro_utils.c \
				$(SRC)utils.c \
				$(SRC)write.c \
				$(SRC)parsing_2.c
			
OBJECTS		=	$(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SOURCES))

# Compiler and Flags
CC			=	cc
LDFLAGS		=	-L$(PRINTF) -lftprintf
CFLAGS		=	-Wall -Wextra -Werror -g

# Default Target
all: $(NAME)

# Build the executable
$(NAME): $(OBJECTS)
	@$(MAKE) -s -C $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LDFLAGS)
	@echo "All files were created"

# Rule for building object files
$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJ_DIR)
	@echo "Object files were cleaned"

# Full clean
fclean: clean
	@$(MAKE) -s -C $(PRINTF) clean
	@rm -f $(NAME)
	@echo "All files were cleaned"

# Rebuild everything
re: fclean all

norminette:
	norminette $(SRC)
	norminette $(PRINTF)

# Phony targets
.PHONY: all clean fclean re