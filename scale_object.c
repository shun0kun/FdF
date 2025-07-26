// #include "header.h"

// void	init_scale_mat(double A[4][4], t_param param)
// {
// 	A[0][0] = param.S;
// 	A[0][1] = 0;
// 	A[0][2] = 0;
// 	A[0][3] = 0;
// 	A[1][0] = 0;
// 	A[1][1] = param.S;
// 	A[1][2] = 0;
// 	A[1][3] = 0;
// 	A[2][0] = 0;
// 	A[2][1] = 0;
// 	A[2][2] = param.S;
// 	A[2][3] = 0;
// 	A[3][0] = 0;
// 	A[3][1] = 0;
// 	A[3][2] = 0;
// 	A[3][3] = 1;
// }

// void	init_scale_func_array(void	(*f[3])(double A[4][4], t_param))
// {
// 	f[0] = init_go_to_origin_mat;
// 	f[1] = init_scale_mat;
// 	f[2] = init_return_mat;
// }

// void	scale_object(int x, int y, int *tx, int *ty, t_param param)
// {
// 	void	(*f[3])(double A[4][4], t_param);
// 	double	v[4][1];
// 	double	A[4][4];
// 	int		i;

// 	init_scale_func_array(f);
// 	init_v(v, x, y);
// 	i = 0;
// 	while (i < 3)
// 	{
// 		f[i](A, param);
// 		mat_mul(A, v);
// 		i++;
// 	}
// 	*tx = (int)v[0][0];
// 	*ty = (int)v[1][0];
// }