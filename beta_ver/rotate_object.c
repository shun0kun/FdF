// #include "header.h"

// void	init_rotatex_mat(double A[4][4], t_param param)
// {
// 	A[0][0] = 1;
// 	A[0][1] = 0;
// 	A[0][2] = 0;
// 	A[0][3] = 0;
// 	A[1][0] = 0;
// 	A[1][1] = cos(param.theta_x);
// 	A[1][2] = -sin(param.theta_x);
// 	A[1][3] = 0;
// 	A[2][0] = 0;
// 	A[2][1] = sin(param.theta_x);
// 	A[2][2] = cos(param.theta_x);
// 	A[2][3] = 0;
// 	A[3][0] = 0;
// 	A[3][1] = 0;
// 	A[3][2] = 0;
// 	A[3][3] = 1;
// }

// void	init_rotatey_mat(double A[4][4], t_param param)
// {
// 	A[0][0] = cos(param.theta_y);
// 	A[0][1] = 0;
// 	A[0][2] = sin(param.theta_y);
// 	A[0][3] = 0;
// 	A[1][0] = 0;
// 	A[1][1] = 1;
// 	A[1][2] = 0;
// 	A[1][3] = 0;
// 	A[2][0] = -sin(param.theta_y);
// 	A[2][1] = 0;
// 	A[2][2] = cos(param.theta_y);
// 	A[2][3] = 0;
// 	A[3][0] = 0;
// 	A[3][1] = 0;
// 	A[3][2] = 0;
// 	A[3][3] = 1;
// }

// void	init_rotatez_mat(double A[4][4], t_param param)
// {
// 	A[0][0] = cos(param.theta_z);
// 	A[0][1] = -sin(param.theta_z);
// 	A[0][2] = 0;
// 	A[0][3] = 0;
// 	A[1][0] = sin(param.theta_z);
// 	A[1][1] = cos(param.theta_z);
// 	A[1][2] = 0;
// 	A[1][3] = 0;
// 	A[2][0] = 0;
// 	A[2][1] = 0;
// 	A[2][2] = 1;
// 	A[2][3] = 0;
// 	A[3][0] = 0;
// 	A[3][1] = 0;
// 	A[3][2] = 0;
// 	A[3][3] = 1;
// }

// void	init_rotate_func_array(void	(*f[5])(double A[4][4], t_param))
// {
// 	f[0] = init_go_to_origin_mat;
// 	f[1] = init_rotatex_mat;
// 	f[2] = init_rotatey_mat;
// 	f[3] = init_rotatez_mat;
// 	f[4] = init_return_mat;
// }

// void	rotate_object(int x, int y, int *tx, int *ty, t_param param)
// {
// 	void	(*f[5])(double A[4][4], t_param);
// 	double	v[4][1];
// 	double	A[4][4];
// 	int		i;

// 	init_rotate_func_array(f);
// 	init_v(v, x, y);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		f[i](A, param);
// 		mat_mul(A, v);
// 		i++;
// 	}
// 	*tx = v[0][0];
// 	*ty = v[1][0];
// }