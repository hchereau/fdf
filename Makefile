NAME = fdf

### LIBFT
LIBFT_FOLDER += libft/
LIBFT += $(LIBFT_FOLDER)/libft.a
### MLX

MLX_FOLDER = minilibx-linux/
LIB_MLX = $(MLX_FOLDER)/libmlx.a

### SRCS

PATH_SRCS = srcs/

SRCS += main.c
SRCS += utils_matrice.C

vpath %.c $(PATH_SRCS)
### OBJS

PATH_OBJS = objs/

OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### INCLUDES

INCLUDES_FDF = includes/
INCLUDES_LIBFT += $(LIBFT_FOLDER)/includes/
INCLUDES_MLX = $(MLX_FOLDER)/
INCLUDES += -I $(INCLUDES_FDF)
INCLUDES += -I $(INCLUDES_MLX)
INCLUDES += -I $(INCLUDES_LIBFT)

HEADERS += $(INCLUDES_FDF)/fdf.h

### COMPILATION

CC = clang
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -Wall

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined -g3
endif

LINKS += -Lmlx-linux
LINKS += -L/usr/lib
LINKS += -lXext
LINKS += -lX11
LINKS += -lm
LINKS += -lz

### TEST

TEST_FOLDER = fdf_tester/
RUN_TESTS = $(TEST_FOLDER)/run_test

all: $(NAME)

$(NAME): $(LIB_MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LINKS) $(OBJS) -o $(NAME) $(LIB_MLX)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS)
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -O3 -c $< -o $@ $(INCLUDES)

$(LIB_MLX):
	$(MAKE) -C $(MLX_FOLDER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_FOLDER)

#test: $(NAME)
#		$(MAKE) -sC $(TEST_FOLDER)
#		echo -n "\n<------TESTS------>\n\n\n"
#		./$(RUN_TESTS)
clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -C $(MLX_FOLDER) clean

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re