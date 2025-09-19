#include "internal/fdf.h"

void	mat4_mul_vec4(t_mat4 model, float vec[4][1])
{
	int		i;
	int		j;
	float	new_vec[4][1];

	new_vec[0][0] = 0;
	new_vec[1][0] = 0;
	new_vec[2][0] = 0;
	new_vec[3][0] = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new_vec[i][0] += model[i][j] * vec[j][0];
			j++;
		}
		i++;
	}
	vec[0][0] = new_vec[0][0];
	vec[1][0] = new_vec[1][0];
	vec[2][0] = new_vec[2][0];
	vec[3][0] = new_vec[3][0];
}

void	update_point(t_point *point, t_mat4 model)
{
	float	vec[4][1];

	vec[0][0] = point->x;
	vec[1][0] = point->y;
	vec[2][0] = point->z;
	vec[3][0] = 1;
	mat4_mul_vec4(model, vec);
	point->x = vec[0][0];
	point->y = vec[1][0];
	point->z = vec[2][0];	
}

void	update_points(t_grid grid, t_mat4 model)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid.rows)
	{
		j = 0;
		while (j < grid.cols)
		{
			update_point(&grid.points[i][j], model);
			j++;
		}
		i++;
	}
}

void	update_base_point(t_point *base_point, t_mat4 model)
{
	update_point(base_point, model);
}