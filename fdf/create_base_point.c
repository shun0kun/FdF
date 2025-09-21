#include "internal/fdf.h"

void	create_base_point(t_grid *grid)
{
	int	z_max;
	int	z_min;
	int	i;
	int	j;

	z_max = 0;
	z_min = 0;
	i = 0;
	while (i < grid->rows)
	{
		j = 0;
		while (j < grid->cols)
		{
			if (z_max > grid->points[i][j].z)
				z_max = grid->points[i][j].z;
			if (z_min < grid->points[i][j].z)
				z_min = grid->points[i][j].z;
			j++;
		}
		i++;
	}
	grid->base_point.x = IMAGE_WIDTH / 2;
	grid->base_point.y = IMAGE_HEIGHT / 2;
	grid->base_point.z = (int)((z_max + z_min) * 0.5f);
	grid->base_point.color = 0x00FF0000;
}