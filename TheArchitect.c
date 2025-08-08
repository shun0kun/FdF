/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheArchitect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:48 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/08 18:52:43 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_atohexaui(char *s)
{
	int				i;
	unsigned int	res;
	unsigned int	dig;

	i += 2;
	res = 0x00000000;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			dig = 0x00000000 + (s[i] - '0');
		else
			dig = 0x0000000A + (s[i] - 'A');
		res = res * 16 + dig;
	}
	return (res);
}

unsigned int	extract_color_unit(char *token)
{
	int		i;
	char	*s;

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
		return (ft_atohexaui(s));
	}
	else
		return (0x00000000);
}

void	translate_unit(t_ctx *ctx)
{
	char	*line;
	char	**tokens;
	int		i;
	int		j;

	ctx->fd = open(ctx->filename, O_RDONLY);
	if (ctx->fd < 0)
		TheAnnihilator("File open fale\n", ctx);
	i = 0;
	while (1)
	{
		line = get_next_line(ctx->fd);
		if (!line)
			break ;
		tokens = ft_split(line, " ");
		while (j < ctx->width)
		{
			ctx->points[i][j].x = i;
			ctx->points[i][j].y = j;
			ctx->points[i][j].z = ft_atoi(tokens[j]);
			ctx->points[i][j].color = extract_color_unit(tokens[j]);
			j++;
		}
		i++;
	}
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
	translate_unit(ctx);
	close(ctx->fd);
	
}
