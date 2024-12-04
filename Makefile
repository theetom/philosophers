# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 14:44:14 by toferrei          #+#    #+#              #
#    Updated: 2024/12/04 15:32:03 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo

LIBFT       = Libft/
PRINTF      = Ft_Printf/
SRC         = Sources/
OBJ_DIR     = Objects/
LIBFT_A     = $(LIBFT)libft.a
PRINTF_A    = $(PRINTF)libftprintf.a

# Sources and Objects
SOURCES     = $(wildcard $(SRC)*.c) # All .c files in Sources/
OBJECTS     = $(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SOURCES))

# Compiler and Flags
CC          = cc
LDFLAGS     = -L$(PRINTF) -L$(LIBFT) -lftprintf -lft
CFLAGS      = -Wall -Wextra -Werror -g

# Default Target
all: $(NAME)

# Build the executable
$(NAME): $(OBJECTS)
	@$(MAKE) -s -C $(LIBFT)
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
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(PRINTF) clean
	@rm -f $(NAME)
	@echo "All files were cleaned"

# Rebuild everything
re: fclean all

norminette:
	norminette $(SRC)
	norminette $(PRINTF)
	norminette $(LIBFT)

# Phony targets
.PHONY: all clean fclean re