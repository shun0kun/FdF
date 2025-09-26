/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:57:40 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:01:09 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

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
	i = -1;
	if (is_minus)
	{
		while (++i < 10)
		{
			if (n[i] > int_min_abs[i])
				return (false);
		}
	}
	else
	{
		while (++i < 10)
		{
			if (n[i] > int_max[i])
				return (false);
		}
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
