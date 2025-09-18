#include "internal/fdf.h"

ç
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

ç
{
	if (m > n)
		return (m);
	else
		return (n);
}

ç
{
	if (point.x >= 0 && point.x < IMAGE_WIDTH && point.y >= 0
		&& point.y < IMAGE_HEIGHT)
	{
		*(unsigned int *)(mlx.addr + point.y * mlx.ll + point.x
				* (mlx.bpp / 8)) = point.color;
	}
}

ç
{
	t_point	p;

	p.y = 0;
	while (p.y < IMAGE_HEIGHT)
	{
		p.x = 0;
		while (p.x < IMAGE_WIDTH)
		{
			put_pixel_to_image(mlx, p);
			p.x++;
		}
		p.y++;
	}
}

ç
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
}
