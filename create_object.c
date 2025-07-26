#include "header.h"

// void	init_event_func_array(void (*f[3])(int, int, int *, int *, t_param))
// {
// 	f[0] = NULL;
// 	f[1] = translate_object;
// 	f[2] = rotate_object;
// 	f[3] = scale_object;
// }

void	create_object(t_ctx ctx)
{
	// void	(*f[4])(int, int, int *, int *, t_param);
	int		center_x;
	int		center_y;
	int		r;
	int		i;
	int		j;

	// init_event_func_array(f);
	center_x = 480;
	center_y = 270;
	r = 50;
	i = 0;
	while (i < 500)
	{
		j = 0;
		if (i % 50 == 0)
		{
			while (j < 50)
			{
				put_pixel_to_image(ctx, center_x + r * cos(2 * M_PI * i / 500) * j / 50, center_y + r * sin(2 * M_PI * i / 500) * j / 50, 0x0000FFFF, move_object);
				j++;
			}
		}
		put_pixel_to_image(ctx, (int)(center_x + r * cos(2 * M_PI * i / 500)), (int)(center_y + r * sin(2 * M_PI * i / 500)), 0x0000FFFF, move_object);
		i++;
	}
}