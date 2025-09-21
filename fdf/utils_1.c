#include "internal/fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_max(int m, int n)
{
	if (m > n)
		return (m);
	else
		return (n);
}

void	put_pixel_to_image(t_mlx mlx, t_point point)
{
	if (point.x >= 0 && point.x < IMAGE_WIDTH && point.y >= 0
		&& point.y < IMAGE_HEIGHT)
	{
		*(unsigned int *)(mlx.addr + point.y * mlx.ll + point.x
				* (mlx.bpp / 8)) = point.color;
	}
}

void	clean_image(t_mlx mlx)
{
	t_point	p;

	p.color = 0x00000000;
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

void	fill_matrix4x4_zero(t_mat4 mat)
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
