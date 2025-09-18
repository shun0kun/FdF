#include "internal/fdf.h"

void	init_to_origin_transform(t_transforms *transforms)
{
	const t_mat4	mat = {{1, 0, 0, -(float)(IMAGE_WIDTH / 2)},
	{0, 1, 0, -(float)(IMAGE_HEIGHT / 2)},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	ft_memcpy(transforms->to_origin, mat, sizeof(mat));
}

void	init_from_origin_transforms(t_transforms *transforms)
{
	const t_mat4	mat = {{1, 0, 0, (float)(IMAGE_WIDTH / 2)},
	{0, 1, 0, (float)(IMAGE_HEIGHT / 2)},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	ft_memcpy(transforms->from_origin, mat, sizeof(mat));
}