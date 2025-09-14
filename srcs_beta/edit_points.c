#include "internal/fdf.h"

t_point	multiply_matrix(t_ctx *ctx, float x[4][1])
{
	int		i;
	int		j;
	float	res[4][1];
	t_point	new_p;

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
			res[i][0] += ctx->affine_matrix[i][j] * x[j][0];
			j++;
		}
		i++;
	}
	new_p.x = (int)res[0][0];
	new_p.y = (int)res[1][0];
	new_p.z = (int)res[2][0];
	return (new_p);
}

void	edit_a_point(t_ctx *ctx, int i, int j)
{
	t_point	new_p;
	float	x[4][1];

	x[0][0] = ctx->points[i][j].x;
	x[1][0] = ctx->points[i][j].y;
	x[2][0] = ctx->points[i][j].z;
	x[3][0] = 1;
	new_p = multiply_matrix(ctx, x);
	ctx->points[i][j].x = new_p.x;
	ctx->points[i][j].y = new_p.y;
	ctx->points[i][j].z = new_p.z;
}

void	edit_points(t_ctx *ctx, int keycode)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->height)
	{
		j = 0;
		while (j < ctx->width)
		{
			edit_a_point(ctx, i, j);
			j++;
		}
		i++;
	}
}

//base_pointも編集しないと！

//ctxのheight, width, points, affine_matrixを使う。
