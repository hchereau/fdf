NAME = run_test

### LIBFT

LIBFT_FOLDER += ../libft/
LIBFT += $(LIBFT_FOLDER)/libft.a

### SRCS

PATH_SRCS = srcs/

MAIN_SRCS = $(PATH_SRCS)/main.test.c

SRCS += utils_matrice.test.c

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### INCLUDES

INCLUDES_LIBFT += $(LIBFT_FOLDER)/includes/
INCLUDES = -I../
TEST_INCLUDES = -Iincludes/
HEADER = $(INCLUDES)/fdf.test.h

### FDF

PATH_TEST_SRCS = ../srcs/

SRCS_TEST += utils_matrice.c

vpath %.c $(PATH_TEST_SRCS)

### COMPILATION

CC = clang

CFLAGS += Werror
CFLAGS += Wextra
CFLAGS += Wall

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS_TEST) $(M)