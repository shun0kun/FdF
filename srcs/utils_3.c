#include "internal/fdf.h"

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
	if (*token == '0' && is_digit(*(token + 1)))
		return (true);
	else
		return (false);
}