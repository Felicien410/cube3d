NAME = cube

OBJS = ${SRCS:.c=.o}

SRCS =	srcs/main.c \
		srcs/graphism/events.c \
		srcs/graphism/events2.c \
		srcs/graphism/utils.c \
		srcs/graphism/inits.c \
		srcs/graphism/inits2.c \
		srcs/graphism/raycast.c \
		srcs/graphism/raycast2.c \
		srcs/graphism/floor_ceiling.c \
		srcs/parsing/checks.c \
		srcs/parsing/checks2.c \
		srcs/parsing/gnl.c \
		srcs/parsing/gnl2.c \
		srcs/parsing/lib1.c \
		srcs/parsing/verif.c \
		srcs/parsing/add_data.c \
		srcs/parsing/add_data2.c \
		srcs/parsing/check_map.c \
		srcs/parsing/add_map.c \


HEADERS =	-I ./Includes/fractol.h

FLAGS =	-Wall -Wextra -Werror

$(NAME):
		gcc -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit $(HEADERS) $(FLAGS) -O3 -o $(NAME) $(SRCS) -fsanitize=address
all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean bonus
