/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transforms_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:03:03 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:17:15 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	init_translation_transforms(t_trs *trs)
{
	const t_mat4	mat1 = {{1, 0, 0, -TRANSLATE_PIXEL},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	const t_mat4	mat2 = {{1, 0, 0, 0},
	{0, 1, 0, -TRANSLATE_PIXEL},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	const t_mat4	mat3 = {{1, 0, 0, TRANSLATE_PIXEL},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	const t_mat4	mat4 = {{1, 0, 0, 0},
	{0, 1, 0, TRANSLATE_PIXEL},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	ft_memcpy(trs->translate_left, mat1, sizeof(mat1));
	ft_memcpy(trs->translate_up, mat2, sizeof(mat2));
	ft_memcpy(trs->translate_right, mat3, sizeof(mat3));
	ft_memcpy(trs->translate_down, mat4, sizeof(mat4));
}

void	init_rotation_transforms_1(t_trs *trs)
{
	const t_mat4	mat1 = {{1, 0, 0, 0},
	{0, (float)cos(-ROTATE_RAD), (float)(-sin(-ROTATE_RAD)), 0},
	{0, (float)sin(-ROTATE_RAD), (float)cos(-ROTATE_RAD), 0},
	{0, 0, 0, 1}};
	const t_mat4	mat2 = {{1, 0, 0, 0},
	{0, (float)cos(ROTATE_RAD), (float)(-sin(ROTATE_RAD)), 0},
	{0, (float)sin(ROTATE_RAD), (float)cos(ROTATE_RAD), 0},
	{0, 0, 0, 1}};
	const t_mat4	mat3
		= {{(float)cos(ROTATE_RAD), 0, (float)sin(ROTATE_RAD), 0},
	{0, 1, 0, 0},
	{(float)(-sin(ROTATE_RAD)), 0, (float)cos(ROTATE_RAD), 0},
	{0, 0, 0, 1}};
	const t_mat4	mat4
		= {{(float)cos(-ROTATE_RAD), 0, (float)sin(-ROTATE_RAD), 0},
	{0, 1, 0, 0},
	{(float)(-sin(-ROTATE_RAD)), 0, (float)cos(-ROTATE_RAD), 0},
	{0, 0, 0, 1}};

	ft_memcpy(trs->rotate_x_minus, mat1, sizeof(mat1));
	ft_memcpy(trs->rotate_x_plus, mat2, sizeof(mat2));
	ft_memcpy(trs->rotate_y_minus, mat3, sizeof(mat3));
	ft_memcpy(trs->rotate_y_plus, mat4, sizeof(mat4));
}

void	init_rotation_transforms_2(t_trs *trs)
{
	const t_mat4	mat5
		= {{(float)cos(-ROTATE_RAD), (float)(-sin(-ROTATE_RAD)), 0, 0},
	{(float)sin(-ROTATE_RAD), (float)cos(-ROTATE_RAD), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	const t_mat4	mat6
		= {{(float)cos(ROTATE_RAD), (float)(-sin(ROTATE_RAD)), 0, 0},
	{(float)sin(ROTATE_RAD), (float)cos(ROTATE_RAD), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	ft_memcpy(trs->rotate_z_minus, mat5, sizeof(mat5));
	ft_memcpy(trs->rotate_z_plus, mat6, sizeof(mat6));
}

void	init_scale_transforms(t_trs *trs)
{
	const t_mat4	mat1 = {{1 + SCALE_DELTA, 0, 0, 0},
	{0, 1 + SCALE_DELTA, 0, 0},
	{0, 0, 1 + SCALE_DELTA, 0},
	{0, 0, 0, 1}};
	const t_mat4	mat2 = {{1 - SCALE_DELTA, 0, 0, 0},
	{0, 1 - SCALE_DELTA, 0, 0},
	{0, 0, 1 - SCALE_DELTA, 0},
	{0, 0, 0, 1}};

	ft_memcpy(trs->scale_up, mat1, sizeof(mat1));
	ft_memcpy(trs->scale_down, mat2, sizeof(mat2));
}

void	init_transforms(t_trs *trs)
{
	init_translation_transforms(trs);
	init_rotation_transforms_1(trs);
	init_rotation_transforms_2(trs);
	init_scale_transforms(trs);
	init_to_origin_transform(trs);
	init_from_origin_transform(trs);
}
