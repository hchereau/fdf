NAME = fdf

### MAKEFILE

MAKEFILE = Makefile

### LIBFT
LIBFT_FOLDER += libft/
LIBFT += $(LIBFT_FOLDER)/libft.a

### MLX

MLX_FOLDER = minilibx-linux/
LIB_MLX = $(MLX_FOLDER)/libmlx.a

### SRCS

PATH_SRCS += srcs/
PATH_SRCS += srcs/matrix_char/
PATH_SRCS += srcs/matrix_vertex/
PATH_SRCS += srcs/utils/
PATH_SRCS += srcs/matrix_vertex/cp_vertex_matrix/
PATH_SRCS += srcs/window/

SRCS += ft_csplit.c
SRCS += utils_matrix.c
SRCS += utils_matrix_vertex.c
SRCS += base_convert.c
SRCS += print_matrix.c
SRCS += free_matrix.c
SRCS += utils_vertex.c
SRCS += zoom.c
SRCS += copy_matrix_vertex.c
SRCS += hook_key.c
SRCS += main.c

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
LINKS += -fPIE

### TEST

TEST_FOLDER = fdf_tester/
RUN_TESTS = $(TEST_FOLDER)/run_test

all: $(NAME)

$(NAME): $(LIB_MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LINKS) $(LIB_MLX) $(LIBFT)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS) $(MAKEFILE)
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -O3

$(LIB_MLX):
	$(MAKE) -C $(MLX_FOLDER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_FOLDER)

test: $(NAME)
		$(MAKE) -sC $(TEST_FOLDER)
		echo -n "\n<------TESTS------>\n\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(RUN_TESTS)
clean:
	$(RM) -r $(PATH_OBJS)
	$(MAKE) -C $(MLX_FOLDER) clean
	$(MAKE) -C $(LIBFT_FOLDER) clean
	$(MAKE) -C $(TEST_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	$(MAKE) -C $(TEST_FOLDER) fclean

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
.SILENT: test
