#include "header.h"

void	put_pixel_to_image(t_ctx ctx, int x, int y, unsigned int color, void (*f)(int, int, int *, int *, t_param))
{
	int	tx;
	int	ty;

	if (f)
	{
		f(x, y, &tx, &ty, ctx.param);
		*(unsigned int *)(ctx.addr + tx * (ctx.bpp / 8) + ty * ctx.ll) = color;		
	}
	else
	{
		*(unsigned int *)(ctx.addr + x * (ctx.bpp / 8) + y * ctx.ll) = color;
	}
}

void	clear_image(t_ctx ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < 540)
	{
		x = 0;
		while (x < 960)
		{
			put_pixel_to_image(ctx, x, y, 0x00000000, NULL);
			x++;
		}
		y++;
	}
}

void	init_v(double v[4][1], int x, int y)
{
	v[0][0] = x;
	v[1][0] = y;
	v[2][0] = 0;
	v[3][0] = 1;	
}

void	mat_mul(double A[4][4], double v[4][1])
{
	double	res[4][1];
	int		i;
	int		j;
	
	res[0][0] = 0;	
	res[1][0] = 0;
	res[2][0] = 0;
	res[3][0] = 0;	
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][0] += A[i][j] * v[j][0];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		v[i][0] = res[i][0];
		i++;
	}
}