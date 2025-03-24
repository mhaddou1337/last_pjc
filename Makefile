CC = gcc 
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
BONUS = fractol_bonus
MANDATORY_DIR = mandatory
BONUS_DIR = bonus

FILES_MANDATORY = draw.c utility_b.c utility_c.c fractol.c  julia.c    mandelbrot.c    utility_a.c  utility_d.c
FILES_BONUS = draw_bonus.c utility_b_bonus.c  julia_bonus.c mandelbrot_bonus.c tricorn_bonus.c utility_c_bonus.c fractol_bonus.c utility_a_bonus.c utility_d_bonus.c

SRC_MANDATORY = $(addprefix $(MANDATORY_DIR)/, $(FILES_MANDATORY))
SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(FILES_BONUS))

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)


all: $(NAME)
bonus: $(BONUS)

$(NAME) : $(OBJ_MANDATORY)
	${CC} ${CFLAGS} $(OBJ_MANDATORY) -o $(NAME)  -lmlx  -lX11 -lXext -lm 

$(BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS) -lmlx  -lX11 -lXext -lm 

clear: 
	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
fclear: clear
	rm -f $(NAME) $(BONUS)
re : clear all

.PHONY: all clear re bonus