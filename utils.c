#include "fdf.h"

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

void	put_pixel_to_image(t_ctx *ctx, t_point point)
{
	if (point.x >= 0 && point.x < IMAGE_WIDTH && point.y >= 0
		&& point.y < IMAGE_HEIGHT)
	{
		*(unsigned int *)(ctx->mlx.addr + point.y * ctx->mlx.ll + point.x
				* (ctx->mlx.bpp / 8)) = point.color;
	}
}
