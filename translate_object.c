// #include "header.h"

// void	init_translate_mat(double A[4][4], t_param param)
// {
// 	A[0][0] = 1;
// 	A[0][1] = 0;
// 	A[0][2] = 0;
// 	A[0][3] = param.Tx;
// 	A[1][0] = 0;
// 	A[1][1] = 1;
// 	A[1][2] = 0;
// 	A[1][3] = param.Ty;
// 	A[2][0] = 0;
// 	A[2][1] = 0;
// 	A[2][2] = 1;
// 	A[2][3] = 0;
// 	A[3][0] = 0;
// 	A[3][1] = 0;
// 	A[3][2] = 0;
// 	A[3][3] = 1;
// }

// void	translate_object(int x, int y, int *tx, int *ty, t_param param)
// {
// 	double	v[4][1];
// 	double	A[4][4];

// 	init_v(v, x, y);
// 	init_translate_mat(A, param);
// 	mat_mul(A, v);
// 	*tx = (int)v[0][0];
// 	*ty = (int)v[1][0];
// }