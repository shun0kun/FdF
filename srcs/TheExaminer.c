/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheExaminer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:52 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/15 19:12:10 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

int	is_correct_token(char *token)
{
	int	i;

	i = 0;
	while (*token >= '0' && *token <= '9')
		token++;
	if (*token == '\0')
		return (1);
	else if (*token == ',')
	{
		token++;
		if (*token == '\0' || *token != '0')
			return (0);
		token++;
		if (*token == '\0' || *token != 'x')
			return (0);
		token++;
		while ((token[i] >= '0' && token[i] <= '9') || (token[i] >= 'A' && token[i] <= 'F'))
			i++;
		if (i != 8)
			return (0);
	}
	return (1);
}

void	check_unit(char **tokens, t_ctx *ctx, int *start_flag)
{
	int	count;

	count = 0;
	while (tokens[count])
	{
		if (!is_correct_token(tokens[count]))
			TheAnnihilator(NULL, ctx);
		count++;
	}
	if (!*start_flag && ctx->width != count)
		TheAnnihilator(NULL, ctx);
	*start_flag = 0;
	ctx->width = count;
}

void	TheExaminer(t_ctx *ctx)
{
	int		fd;
	char	*line;
	char	**tokens;
	int		start_flag;

	start_flag = 1;
	fd = open(ctx->filename, O_RDONLY);
	if (fd < 0)
		TheAnnihilator(NULL, ctx);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_unit(ft_split(line), ctx, &start_flag);
		ctx->height++;
	}
	close(ctx->fd);
}
