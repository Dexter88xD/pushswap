# This is the brain of the whole operation.
# Let's get this ship going!

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I $(LIBFT)
LIB_FLAGS = -L$(LIBFT) -lft
RM = rm -rf

LIBFT = ./libft/
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

NAME = push_swap
BS_NAME = checker

SRCS =	check_numbers.c		find_min_max.c	push_swap.c			setting_target.c	\
		dumping_stacks.c	main.c			reverse_rotate.c  	sorting.c			\
		find_cheap_cost.c	rotate.c		update_stack.c							\

BSRCS =	main_bonus.c			check_numbers_bonus.c		rotate_bonus.c	push_swap_bonus.c	\
		reverse_rotate_bonus.c	follow_instructions_bonus.c

S_OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BS_OBJECTS = $(addprefix $(BONUS_OBJ_DIR)/, $(BSRCS:.c=.o))

all: $(NAME) 

$(NAME): $(S_OBJECTS) $(LIBFT)/libft.a
	@echo "compiling files!!"
	@$(CC) -o $(NAME) $(S_OBJECTS) $(LIB_FLAGS)
	@echo "Executable ready!!"

bonus: $(BS_NAME)

$(BS_NAME): $(BS_OBJECTS) $(LIBFT)/libft.a
	@echo "compiling bonus files!!"
	@$(CC) -o $(BS_NAME) $(BS_OBJECTS) $(LIB_FLAGS)
	@echo "Bonus executable ready!!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	@$(MAKE) --no-print-directory -C $(LIBFT)

clean:
	@$(MAKE) --no-print-directory fclean -C $(LIBFT)
	@echo "cleaning files!!"
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@$(RM) $(NAME) $(BS_NAME)

re: fclean all

help:
	@echo "Available targets:"
	@echo "  make          - Build the main executable"
	@echo "  make bonus    - Build the bonus executable"
	@echo "  make clean    - Remove object files"
	@echo "  make fclean   - Remove object files and executables"
	@echo "  make re       - Rebuild everything"

.PHONY: all clean fclean re bonus help
