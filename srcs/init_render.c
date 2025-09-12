#include "internal/fdf.h"

t_render	init_render(t_grid *grid, t_mlx mlx)
{
	t_render	render;

	render.grid = *grid;
	render.mlx = mlx;
	render.model = init_model();
	render.transforms = init_transforms();
	return (render);
}