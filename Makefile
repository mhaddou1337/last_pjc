NAME = fractol

FLAGS = -Wall -Wextra -Werror
CC = cc
SRC_mandatory = draw.c fractol.c julia.c mandelbrot.c utility_a.c v

all: $(NAME)

clean
	rm -rf *.o
fclean
	clear ??
.PHONY 