# This is the brain of the whole operation.
# Let's get this ship going!
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I $(LIBFT)
LIB_FLAGS = -L$(LIBFT) -lft
RM = rm -rf

LIBFT = ./libft/
SRC_DIR = src
BONUS_DIR = src/bonus
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

MAKE_LIBFT = @$(MAKE) files -C $(LIBFT)
FCLEAN_LIBFT = @$(MAKE) fclean -C $(LIBFT)

S_NAME = push_swap
BS_NAME = checker

SRCS = main.c check_numbers.c
BSRCS = 

S_OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJECTS = $(addprefix $(BONUS_OBJ_DIR)/, $(BSRCS:.c=.o))

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
	@$(FCLEAN_LIBFT)
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@$(RM) $(S_NAME)  $(BS_NAME) $(BC_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
