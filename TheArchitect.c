/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheArchitect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:48 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/13 19:00:32 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		else
			dig = 0x0000000A + (s[i] - 'A');
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
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb += s[i] - '0';
		nb *= 10;
		i++;
	}
	return (nb);
}

void	initialize_point(t_ctx *ctx, int i, int j, char *token)
{
	ctx->points[i][j].x = ctx->start_point.x + GRID_WIDTH * j;
	ctx->points[i][j].y = ctx->start_point.y + GRID_HEIGHT * i;
	ctx->points[i][j].z = GRID_ELEVATION * ft_atoi(token);
	ctx->points[i][j].color = extract_color_unit(token);
}

void	translate_unit(t_ctx *ctx)
{
	char	*line;
	char	**tokens;
	int		i;
	int		j;

	ctx->fd = open(ctx->filename, O_RDONLY);
	if (ctx->fd < 0)
		TheAnnihilator("File open fail\n", ctx);
	ctx->start_point.x = IMAGE_WIDTH / 2 - GRID_WIDTH * ctx->width / 2;
	ctx->start_point.y = IMAGE_HEIGHT / 2 - GRID_HEIGHT * ctx->height / 2;
	ctx->start_point.z = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(ctx->fd);
		if (!line)
			break ;
		tokens = ft_split(line, " ");
		while (j < ctx->width)
		{
			initialize_point(ctx, i, j, tokens[j]);
			j++;
		}
		i++;
	}
}

void	initialize_base_point(t_ctx *ctx)
{
	int	z_max;
	int	z_min;
	int	i;
	int	j;

	z_max = 0;
	z_min = 0;
	i = 0;
	while (i < ctx->height)
	{
		j = 0;
		while (j < ctx->width)
		{
			if (z_max > ctx->points[i][j].z)
				z_max = ctx->points[i][j].z;
			if (z_min < ctx->points[i][j].z)
				z_min = ctx->points[i][j].z;
			j++;
		}
		i++;
	}
	ctx->base_point.x = IMAGE_WIDTH / 2;
	ctx->base_point.y = IMAGE_HEIGHT / 2;
	ctx->base_point.z = (int)((float)(z_max + z_min) / (float)2);
	ctx->base_point.color = 0x00000000;
}

void	TheArchitect(t_ctx *ctx)
{
	int	i;

	i = 0;
	ctx->points = malloc(ctx->height * sizeof(t_point *));
	if (!ctx->points)
		Annihilator("Memory allocate fale\n", ctx);
	while (i < ctx->height)
	{
		ctx->points[i] = malloc(ctx->width * sizeof(t_point));
		if (!ctx->points[i])
			TheAnnihilator("Memory allocate fale\n", ctx);
		i++;
	}
	initialize_base_point(ctx);
	translate_unit(ctx);
	close(ctx->fd);
}
