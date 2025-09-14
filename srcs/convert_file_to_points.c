/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file_to_points.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:48 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/14 15:28:18 by sshimots         ###   ########.fr       */
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
		return (0x00000000);
}

int	ft_atoi(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n += s[i] - '0';
		n *= 10;
		i++;
	}
	return (n);
}

void	convert_token_to_point(t_grid *grid, int i, int j, char *token)
{
	grid->points[i][j].x = (IMAGE_WIDTH / 2 - GRID_WIDTH * grid->cols / 2)
					+ GRID_WIDTH * j;
	grid->points[i][j].y = (IMAGE_HEIGHT / 2 - GRID_HEIGHT * grid->rows / 2)
					+ GRID_HEIGHT * i;
	grid->points[i][j].z = GRID_ELEVATION * ft_atoi(token);
	grid->points[i][j].color = extract_color_unit(token);
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		convert_newline_to_null(line);
		tokens = ft_split(line, ' ');
		j = -1;
		while (++j < grid->cols)
			convert_token_to_point(grid, i, j, tokens[j]);
		free_tokens(tokens);
		free(line);
		i++;
	}
	close(fd);
}
