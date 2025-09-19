CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iget_next_line
LDFLAGS = -Llibft -Lget_next_line
LDLIBS = -lgnl -lft -lmlx -lX11 -lXext -lm
NAME = run_fdf
SRCS = fdf/convert_file_to_points.c \
		fdf/create_base_point.c \
		fdf/draw_grid.c \
		fdf/fdf.c \
		fdf/handle_points.c \
		fdf/init_model.c \
		fdf/init_transforms_1.c \
		fdf/init_transforms_2.c \
		fdf/start_rendering.c \
		fdf/update_model.c \
		fdf/update_points.c \
		fdf/utils_1.c \
		fdf/utils_2.c \
		fdf/utils_3.c \
		fdf/validate_file.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
LIBGNL = get_next_line/libgnl.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBGNL)
	$(CC) main.c $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

fdf/%.o: fdf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(LIBGNL):
	$(MAKE) -C get_next_line

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re
