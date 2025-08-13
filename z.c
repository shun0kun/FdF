#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}			t_mlx;

void	render(t_mlx mlx)
{
	int	x;
	int	y;
	int	d_rev;

	y = 100;
	d_rev = 1;
	while (y < 1000)
	{
		x = 100;
		while (x <= 500)
		{
			if (x % d_rev == 0)
				*(unsigned int *)(mlx.addr + y * mlx.ll + x * (mlx.bpp
							/ 8)) = 0x0000FFFF;
			x++;
		}
		y += 50;
		d_rev++;
	}
}

int	ctl_keypress(int keycode, void *param)
{
	t_mlx	mlx;

	mlx = *(t_mlx *)param;
	// printf("%d\n", keycode);
	printf("d");
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "a");
	mlx_hook(mlx.win, 2, 1L << 0, ctl_keypress, &mlx);
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.ll, &mlx.endian);
	printf("%d", mlx.endian);
	// render(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}

//-----------------------------------------------------------------------------------------------//

void	f(t_ctx *ctx, float A[4][4])
{
	float	res[4][4];
	int		i;
	int		j;
	int		k;

	zeros(res);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				res[i][j] = ctx->affine_matrix[i][k] * A[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	copy_matrix4(ctx->affine_matrix, res);
}

void	init_left(t_mats *mats)
{
	const t_mat4	a = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,
		0}};
}
