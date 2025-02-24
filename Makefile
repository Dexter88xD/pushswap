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

MAKE_LIBFT = @$(MAKE) -C $(LIBFT)
FCLEAN_LIBFT = @$(MAKE) fclean -C $(LIBFT)

S_NAME = push_swap
BS_NAME = checker

SRCS =	check_numbers.c		find_min_max.c			push_swap.c			setting_target.c	\
		dumping_stacks.c	main.c					reverse_rotate.c  	sorting.c			\
		find_cheap_cost.c	rotate.c				update_stack.c							\

BSRCS =	main_bonus.c check_numbers_bonus.c rotate_bonus.c reverse_rotate_bonus.c push_swap_bonus.c

S_OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BS_OBJECTS = $(addprefix $(BONUS_OBJ_DIR)/, $(BSRCS:.c=.o))

all: $(S_NAME) 

$(S_NAME): $(S_OBJECTS) $(LIBFT)/libft.a
	$(CC) -o $(S_NAME) $(S_OBJECTS) $(LIB_FLAGS)

bonus: $(BS_NAME)

$(BS_NAME): $(BS_OBJECTS) $(LIBFT)/libft.a
	$(CC) -o $(BS_NAME) $(BS_OBJECTS) $(LIB_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	$(MAKE_LIBFT)

clean:
	$(FCLEAN_LIBFT)
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	$(RM) $(S_NAME)  $(BS_NAME) $(BC_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
