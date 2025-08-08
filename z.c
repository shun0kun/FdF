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
}	t_mlx;

void	render(t_mlx mlx)
{
	int	x;
	int y = 100;
	int	d_rev = 1;

	while (y < 1000)
	{
		x = 100;
		while (x <= 500)
		{
			if (x % d_rev == 0)
				*(unsigned int *)(mlx.addr + y * mlx.ll + x * (mlx.bpp / 8)) = 0x0000FFFF;
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
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "a");
	mlx_hook(mlx.win, 2, 1L<<0, ctl_keypress, &mlx);
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.ll, &mlx.endian);
	// render(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}