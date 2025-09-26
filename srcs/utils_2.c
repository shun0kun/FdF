/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:55:47 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 12:56:49 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	init_to_origin_matrix(t_mat4 to_origin_matrix, t_point base_point)
{
	const t_mat4	a = {{1, 0, 0, -(float)base_point.x},
	{0, 1, 0, -(float)base_point.y},
	{0, 0, 1, -(float)base_point.z},
	{0, 0, 0, 1}};

	ft_memcpy(to_origin_matrix, a, sizeof(a));
}

void	init_off_origin_matrix(t_mat4 off_origin_matrix, t_point base_point)
{
	const t_mat4	a = {{1, 0, 0, (float)base_point.x},
	{0, 1, 0, (float)base_point.y},
	{0, 0, 1, (float)base_point.z},
	{0, 0, 0, 1}};

	ft_memcpy(off_origin_matrix, a, sizeof(a));
}

void	multiply_matrix4x4(const t_mat4 leftmat, const t_mat4 rightmat,
	t_mat4 res)
{
	t_mat4	rightmat_copy;
	t_mat4	leftmat_copy;
	int		i;
	int		j;
	int		k;

	ft_memcpy(rightmat_copy, rightmat, sizeof(t_mat4));
	ft_memcpy(leftmat_copy, leftmat, sizeof(t_mat4));
	fill_matrix4x4_zero(res);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				res[i][j] += leftmat_copy[i][k] * rightmat_copy[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_hex_digit(char c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}
