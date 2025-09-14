#include "internal/fdf.h"

t_point	**create_points(int cols, int rows)
{
	t_point	**points;
	int	i;

	points = malloc(sizeof(t_point *) * rows);
	if (!points)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		points[i] = malloc(sizeof(t_point) * cols);
		if (!points[i])
		{
			while (i > 0)
			{
				i--;
				free(points[i]);
			}
			free(points);
			return (NULL);
		}
		i++;
	}
	return (points);
}

void	destroy_points(t_point **points, int rows)
{
	int	i;

	if (!points)
		return ;
	i = 0;
	while (i < rows)
	{
		free(points[i])
		i++;
	}
	free(points);
}