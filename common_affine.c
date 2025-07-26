#include "header.h"

void	init_go_to_origin_mat(double A[4][4], t_param param)
{
	A[0][0] = 1;
	A[0][1] = 0;
	A[0][2] = 0;
	A[0][3] = -param.Tx - 480;
	A[1][0] = 0;
	A[1][1] = 1;
	A[1][2] = 0;
	A[1][3] = -param.Ty - 270;
	A[2][0] = 0;
	A[2][1] = 0;
	A[2][2] = 1;
	A[2][3] = 0;
	A[3][0] = 0;
	A[3][1] = 0;
	A[3][2] = 0;
	A[3][3] = 1;
}

void	init_return_mat(double A[4][4], t_param param)
{
	A[0][0] = 1;
	A[0][1] = 0;
	A[0][2] = 0;
	A[0][3] = param.Tx + 480;
	A[1][0] = 0;
	A[1][1] = 1;
	A[1][2] = 0;
	A[1][3] = param.Ty + 270;
	A[2][0] = 0;
	A[2][1] = 0;
	A[2][2] = 1;
	A[2][3] = 0;
	A[3][0] = 0;
	A[3][1] = 0;
	A[3][2] = 0;
	A[3][3] = 1;
}

void	init_translate_mat(double A[4][4], t_param param)
{
	A[0][0] = 1;
	A[0][1] = 0;
	A[0][2] = 0;
	A[0][3] = param.Tx;
	A[1][0] = 0;
	A[1][1] = 1;
	A[1][2] = 0;
	A[1][3] = param.Ty;
	A[2][0] = 0;
	A[2][1] = 0;
	A[2][2] = 1;
	A[2][3] = 0;
	A[3][0] = 0;
	A[3][1] = 0;
	A[3][2] = 0;
	A[3][3] = 1;
}

void	init_rotatex_mat(double A[4][4], t_param param)
{
	A[0][0] = 1;
	A[0][1] = 0;
	A[0][2] = 0;
	A[0][3] = 0;
	A[1][0] = 0;
	A[1][1] = cos(param.theta_x);
	A[1][2] = -sin(param.theta_x);
	A[1][3] = 0;
	A[2][0] = 0;
	A[2][1] = sin(param.theta_x);
	A[2][2] = cos(param.theta_x);
	A[2][3] = 0;
	A[3][0] = 0;
	A[3][1] = 0;
	A[3][2] = 0;
	A[3][3] = 1;
}

void	init_rotatey_mat(double A[4][4], t_param param)
{
	A[0][0] = cos(param.theta_y);
	A[0][1] = 0;
	A[0][2] = sin(param.theta_y);
	A[0][3] = 0;
	A[1][0] = 0;
	A[1][1] = 1;
	A[1][2] = 0;
	A[1][3] = 0;
	A[2][0] = -sin(param.theta_y);
	A[2][1] = 0;
	A[2][2] = cos(param.theta_y);
	A[2][3] = 0;
	A[3][0] = 0;
	A[3][1] = 0;
	A[3][2] = 0;
	A[3][3] = 1;
}

void	init_rotatez_mat(double A[4][4], t_param param)
{
	A[0][0] = cos(param.theta_z);
	A[0][1] = -sin(param.theta_z);
	A[0][2] = 0;
	A[0][3] = 0;
	A[1][0] = sin(param.theta_z);
	A[1][1] = cos(param.theta_z);
	A[1][2] = 0;
	A[1][3] = 0;
	A[2][0] = 0;
	A[2][1] = 0;
	A[2][2] = 1;
	A[2][3] = 0;
	A[3][0] = 0;
	A[3][1] = 0;
	A[3][2] = 0;
	A[3][3] = 1;
}

void	init_scale_mat(double A[4][4], t_param param)
{
	A[0][0] = param.S;
	A[0][1] = 0;
	A[0][2] = 0;
	A[0][3] = 0;
	A[1][0] = 0;
	A[1][1] = param.S;
	A[1][2] = 0;
	A[1][3] = 0;
	A[2][0] = 0;
	A[2][1] = 0;
	A[2][2] = param.S;
	A[2][3] = 0;
	A[3][0] = 0;
	A[3][1] = 0;
	A[3][2] = 0;
	A[3][3] = 1;
}