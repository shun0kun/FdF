CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iget_next_line
LDFLAGS = -Llibft -Lget_next_line
LDLIBS = -lgnl -lft -lmlx -lX11 -lXext -lm
NAME = fdf
SRCS = srcs/convert_file_to_points.c \
		srcs/create_base_point.c \
		srcs/draw_grid.c \
		srcs/fdf.c \
		srcs/handle_points.c \
		srcs/init_model.c \
		srcs/init_transforms_1.c \
		srcs/init_transforms_2.c \
		srcs/main.c \
		srcs/start_rendering.c \
		srcs/update_current_points.c \
		srcs/update_model.c \
		srcs/update_points.c \
		srcs/utils_1.c \
		srcs/utils_2.c \
		srcs/utils_3.c \
		srcs/utils_rendering.c \
		srcs/validate_file.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
LIBGNL = get_next_line/libgnl.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBGNL)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

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
