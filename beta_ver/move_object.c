#include "header.h"

void	init_func_array(void (*f[7])(double A[4][4], t_param))
{
	f[0] = init_go_to_origin_mat;
	f[1] = init_scale_mat;
	f[2] = init_rotatex_mat;
	f[3] = init_rotatey_mat;
	f[4] = init_rotatez_mat;
	f[5] = init_return_mat;
	f[6] = init_translate_mat;
}

void	move_object(int x, int y, int *tx, int *ty, t_param param)
{
	void	(*f[7])(double A[4][4], t_param);
	double	v[4][1];
	double	A[4][4];
	int		i;

	init_func_array(f);
	init_v(v, x, y);
	i = 0;
	while (i < 7)
	{
		f[i](A, param);
		mat_mul(A, v);
		i++;
	}
	*tx = (int)v[0][0];
	*ty = (int)v[1][0];
}