#ifndef CONFIG_H
# define CONFIG_H

# ifndef INT_MIN
#  define INT_MIN				-2147483648
# endif
# ifndef INT_MAX
#  define INT_MAX				2147483647
# endif

# define WINDOW_WIDTH			1920
# define WINDOW_HEIGHT			1080
# define IMAGE_WIDTH			1920
# define IMAGE_HEIGHT			1080
# define GRID_WIDTH				30
# define GRID_HEIGHT			40
# define GRID_ELEVATION			3

# ifndef M_PI
#  define M_PI				3.14159265358979323846264338327950288
# endif
# define TRANSLATE_PIXEL	5.0f
# define ROTATE_RAD			(3 * M_PI / 180.0)
# define SCALE_DELTA		0.1f

#endif