/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file_to_points.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:48 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:15:04 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

unsigned int	ft_atohexaui(char *s)
{
	int				i;
	unsigned int	res;
	unsigned int	dig;

	i = 2;
	res = 0x00000000;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			dig = 0x00000000 + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			dig = 0x0000000A + (s[i] - 'A');
		else
			dig = 0x0000000A + (s[i] - 'a');
		res = res * 16 + dig;
		i++;
	}
	return (res);
}

unsigned int	extract_color_unit(char *token)
{
	int		i;
	char	s[11];

	while (*token >= '0' && *token <= '9')
		token++;
	if (*token == ',')
	{
		token++;
		i = 0;
		while (*token)
		{
			s[i] = *token;
			i++;
			token++;
		}
		s[i] = '\0';
		return (ft_atohexaui(s));
	}
	else
		return (0x00FFFFFF);
}

void	convert_token_to_point(t_grid *grid, int i, int j, char *token)
{
	grid->pts[i][j].x = (int)((IMAGE_WIDTH * 0.5f
				- GRID_WIDTH * (grid->cols - 1) * 0.5f)
			+ GRID_WIDTH * j);
	grid->pts[i][j].y = (int)((IMAGE_HEIGHT * 0.5f
				- GRID_HEIGHT * (grid->rows - 1) * 0.5f)
			+ GRID_HEIGHT * i);
	grid->pts[i][j].z = GRID_ELEVATION * ft_atoi(token);
	grid->pts[i][j].color = extract_color_unit(token);
}

int	convert_file_to_points(const char *filename, t_grid *grid)
{
	int		fd;
	char	*line;
	char	**tokens;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (++i)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		convert_newline_to_null(line);
		tokens = ft_split(line, ' ');
		j = -1;
		while (++j < grid->cols)
			convert_token_to_point(grid, i - 1, j, tokens[j]);
		free_tokens(tokens);
		free(line);
	}
	close(fd);
	return (1);
}
