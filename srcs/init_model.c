#include "internal/fdf.h"

void	init_model(t_mat4 model)
{
	const t_mat4	to_origin = {{1, 0, 0, -IMAGE_WIDTH / 2},
	{0, 1, 0, -IMAGE_HEIGHT / 2},
	{0, 0, 1, 0},
	{0, 0, 0, 1},};
	const t_mat4	rotate_z = {{cos(M_PI * 45 / 180), -sin(M_PI * 45 / 180), 0, 0},
	{sin(M_PI * 45 / 180), cos(M_PI * 45 / 180), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	const t_mat4	rotate_x = {{1, 0, 0, 0},
	{0, cos(atan(sqrt(2))), -sin(atan(sqrt(2))), 0},
	{0, sin(atan(sqrt(2))), cos(atan(sqrt(2))), 0},
	{0, 0, 0, 1}};
	const t_mat4	from_origin = {{1, 0, 0, IMAGE_WIDTH / 2},
	{0, 1, 0, IMAGE_HEIGHT / 2},
	{0, 0, 1, 0},
	{0, 0, 0, 1},};

	multiply_matrix4x4(rotate_z, to_origin, model);
	multiply_matrix4x4(rotate_x, model, model);
	multiply_matrix4x4(from_origin, model, model);
}
