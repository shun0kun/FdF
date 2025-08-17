/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheExaminer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:52 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/18 00:54:10 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_hex_digit(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

void	free_tokens(char **tokens)
{
	int	i;

	if (tokens)
	{
		i = 0;
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
	}
	free(tokens);
}

//要訂正
int	validate_token(const char *token)
{
	int	i;
	int	count;

	i = 0;
	while (is_digit(token[i]))
		i++;
	if (i == 0 || token[i] == '\0')
		return (0);
	else if (token[i] == ',')
	{
		i++;
		if (token[i] == '\0' || token[i] != '0')
			return (0);
		i++;
		if (token[i] == '\0' || (token[i] != 'x' && token[i] != 'X'))
			return (0);
		i++;
		count = 0;
		while (is_hex_digit(token[i + count]))
			count++;
		if (count == 0 || count > 8)
			return (0);
	}
	return (1);
}

int	validate_line(const char *line, int *expected_cols, int *is_first_line)
{
	char	**tokens;
	int		count;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	count = 0;
	while (tokens[count])
	{
		if (!validate_token(tokens[count]))
		{
			free_tokens(tokens);
			return (0);
		}
		count++;
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

int	validate_file(const char *filename)
{
	int		fd;
	char	*line;
	int		is_first_line;
	int		expected_cols;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	is_first_line = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!validate_line(line, &expected_cols, &is_first_line))
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

//get_next_lineの戻り値の型をt_errorにして、malloc失敗のNULLとファイル読み取り終了のNULLを区別する！
//→このままだとget_next_lineがmalloc失敗した時にvalidate_fileはERR_OKを返してしまい、次の関数でバグる。
//構造を変えてしまうのではなく、細かく関数に分けて行数を減らす。mallocを子関数で行うことで、freeも子関数で
//→行えるので行数が節約できる。
//gnlだと、lineの最後に\nが含まれてしまうので、これをnullに変えてから色々処理するのがいい。
//ファイルの空行、line最後の改行(実質同じだが)をどうするのかを考えておく。
//validate_tokenのオーバーフロー処理、マイナスintへの対応
//splitもしかしたらタブでも区切らなきゃいけないかもしれない