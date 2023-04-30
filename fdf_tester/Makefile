NAME = run_test

### LIBFT

LIBFT_FOLDER += ../libft/
LIBFT += $(LIBFT_FOLDER)/libft.a

### SRCS_TEST

PATH_SRCS = srcs/

SRCS += main.test.c
SRCS += utils_matrice.test.c
SRCS += ft_csplit.test.c
SRCS += utils.test.c

vpath %.c $(PATH_SRCS)

### OBJS_TEST

### OBJS

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### INCLUDES

INCLUDES_LIBFT += $(LIBFT_FOLDER)/includes/
INCLUDES_FDF_TEST += includes/
INCLUDES_FDF += ../includes/
INCLUDES += -I $(INCLUDES_LIBFT)
INCLUDES += -I $(INCLUDES_FDF_TEST)
INCLUDES += -I $(INCLUDES_FDF)

HEADERS += $(INCLUDES_FDF_TEST)/fdf.test.h
HEADERS += $(INCLUDES_FDF)/fdf.h

### OBJS_TEST

PATH_OBJS_TEST = ../objs/

OBJS_TEST = $(wildcard $(PATH_OBJS_TEST)/*.o)
OBJS_TEST := $(filter-out $(PATH_OBJS_TEST)/main.o, $(OBJS_TEST))

### COMPILATION

CC = clang

CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -Wall

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined -g3
endif

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) $(OBJS_TEST) -o $(NAME) $(LIBFT)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS)
			mkdir -p $(PATH_OBJS)
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean
		$(MAKE)