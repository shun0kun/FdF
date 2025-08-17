/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheExaminer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:52 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/17 16:28:52 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

bool	is_valid_token(char *token)
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
			return (false);
		token++;
		if (*token == '\0' || *token != 'x')
			return (false);
		token++;
		while ((token[i] >= '0' && token[i] <= '9') || (token[i] >= 'A' && token[i] <= 'F'))
			i++;
		if (i != 8)
			return (false);
	}
	return (true);
}

bool	is_valid_line(char **tokens, t_ctx *ctx, int *start_flag)
{
	int	count;

	count = 0;
	while (tokens[count])
	{
		if (!is_valid_token(tokens[count]))
			cleanup_context(NULL, ctx);
		count++;
	}
	if (!*start_flag && ctx->width != count)
		cleanup_context(NULL, ctx);
	*start_flag = 0;
	ctx->width = count;
}

t_error	validate_file(const char *filename)
{
	int		fd;
	int		is_first_line;
	char	*line;

	is_first_line = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_IO);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		is_valid_line(line, &is_first_line);
		free(line);
		ctx->height++;
	}
	close(ctx->fd);
}

//get_next_lineの戻り値の型をt_errorにして、malloc失敗のNULLとファイル読み取り終了のNULLを区別する！