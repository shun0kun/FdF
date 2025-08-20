#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>
#include <get_next_line.h>


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

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		printf("%d\n", is_valid_token(argv[i]));
		i++;
	}
	return (0);
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
	free_str_array(tokens);
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

int	main(void)
{
	printf("%d\n", validate_file("in.txt"));
	return (0);
}