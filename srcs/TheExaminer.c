/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheExaminer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:52 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/20 22:12:59 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_hex_digit(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

bool	is_hex_unsigned_int(char *token)
{
	int	count;

	if (!*token || *token != '0')
		return (false);
	token++;
	if (!*token || (*token != 'X' && *token != 'x'))
		return (false);
	token++;
	count = 0;
	while (is_hex_digit(token[count]))
		count++;
	if (count == 0 || count > 8 || token[count] != '\0')
		return (false);
	return (true);
}

bool	is_int(char *n, bool is_minus)
{
	char	*int_max;
	char	*int_min_abs;
	int		i;

	int_max = "2147483647";
	int_min_abs = "2147483648";
	i = 0;
	if (is_minus)
		while (i < 10)
		{
			if (n[i] > int_min_abs[i])
				return (false);
			i++;
		}
	else
		while (i < 10)
		{
			if (n[i] > int_max[i])
				return (false);
			i++;
		}		
	return (true);
}

bool	is_octal_number(char *token)
{
	if (!*token)
		return (false);
	else if (!*(token + 1))
		return (false);
	if (*token =='0' && is_digit(*(token + 1)))
		return (true);
	else
		return (false);
}

void	convert_newline_to_null(char *line)
{
	int	i;

	i = 0;
	while (line[i] || line[i] != '\n')
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
		if (!is_valid_token(tokens[count]))
		{
			free_str_array(tokens);
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
		convert_newline_to_null(line);
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
//n1_is_bigger_than_n2関数考えてみる。今回は使わないと思うけど。