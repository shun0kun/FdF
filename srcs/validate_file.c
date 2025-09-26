/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:52 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/26 14:52:52 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	convert_newline_to_null(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return ;
	else if (line[i] == '\n')
		line[i] = '\0';
}

bool	is_valid_token(char *token)
{
	int		count;
	bool	is_minus;

	is_minus = 0;
	if (*token == '+' || (*token == '-' && !is_minus++))
		token++;
	if (is_octal_number(token))
		return (false);
	count = 0;
	while (token[count] && is_digit(token[count]))
		count++;
	if (count == 0 || count > 10 || (count == 10 && !is_int(token, is_minus)))
		return (false);
	if (*(token + count) == ',')
	{
		token += count + 1;
		if (!is_hex_unsigned_int(token))
			return (false);
		else
			return (true);
	}
	else if (*(token + count) == '\0')
		return (true);
	else
		return (false);
}

int	validate_line(char *line, int *expected_cols, int *is_first_line)
{
	char	**tokens;
	int		count;

	convert_newline_to_null(line);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	count = 0;
	while (tokens[count])
	{
		if (!is_valid_token(tokens[count++]))
		{
			free_tokens(tokens);
			return (0);
		}
	}
	free_tokens(tokens);
	if (*is_first_line)
	{
		*expected_cols = count;
		*is_first_line = 0;
	}
	else if (count != *expected_cols)
		return (0);
	return (1);
}

int	validate_file(const char *filename, int *out_cols, int *out_rows)
{
	int		fd;
	char	*line;
	int		is_first_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	*out_rows = 0;
	is_first_line = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*out_rows)++;
		if (!validate_line(line, out_cols, &is_first_line))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}
