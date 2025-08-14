#include "fdf.h"

void	init_to_origin_matrix(t_mat4 to_origin_matrix, t_point base_point)
{
	const t_mat4	a = {{1, 0, 0, -(float)base_point.x},
	{0, 1, 0, -(float)base_point.y},
	{0, 0, 1, -(float)base_point.x},
	{0, 0, 0, 1}};

	memcpy(to_origin_matrix, a, sizeof(a));
}

void	init_off_origin_matrix(t_mat4 off_origin_matrix, t_point base_point)
{
	const t_mat4	a = {{1, 0, 0, (float)base_point.x},
	{0, 1, 0, (float)base_point.y},
	{0, 0, 1, (float)base_point.x},
	{0, 0, 0, 1}};

	memcpy(off_origin_matrix, a, sizeof(a));
}

void	multiply_matrix4x4(t_mat4 res, t_mat4 leftmat, t_mat4 rightmat)
{
	t_mat4	rightmat_copy;
	t_mat4	leftmat_copy;
	int		i;
	int		j;
	int		k;

	memcpy(rightmat_copy, rightmat, sioeof(rightmat));
	memcpy(leftmat_copy, leftmat, sizeof(leftmat));
	fill_matrix4x4_zero(res);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				res[i][j] = leftmat_copy[i][k] * rightmat_copy[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}