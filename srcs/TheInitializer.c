/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheInitializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:56 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/15 19:12:10 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	initialize_isometric_projection_matrix(t_mat4 matrix)
{
	const t_mat4	to_origin_matrix = {{1, 0, 0, -IMAGE_WIDTH / 2},
	{0, 1, 0, -IMAGE_HEIGHT / 2},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	};
	const t_mat4	rotate_z_matrix = {{cos(M_PI * 45 / 180), -sin(M_PI * 45 / 180), 0, 0},
	{sin(M_PI * 45 / 180), cos(M_PI * 45 / 180), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	const t_mat4	rotate_x_matrix = {{1, 0, 0, 0},
	{0, cos(atan(sqrt(2))), -sin(atan(sqrt(2))), 0},
	{0, sin(atan(sqrt(2))), cos(atan(sqrt(2))), 0},
	{0, 0, 0, 1}};
	const t_mat4	off_origin_matrix = {{1, 0, 0, IMAGE_WIDTH / 2},
	{0, 1, 0, IMAGE_HEIGHT / 2},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	};

	multiply_matrix4x4(matrix, rotate_z_matrix, to_origin_matrix);
	multiply_matrix4x4(matrix, rotate_x_matrix, matrix);
	multiply_matrix4x4(matrix, off_origin_matrix, matrix);
}

void	initialize_translation_matrix(t_mats *mats)
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

	memcpy(mats->left, mat1, sizeof(mat1));
	memcpy(mats->up, mat2, sizeof(mat2));
	memcpy(mats->right, mat3, sizeof(mat3));
	memcpy(mats->down, mat4, sizeof(mat4));	
}

void	initialize_rotation_matrix_1(t_mats *mats)
{
	const t_mat4	mat1 = {{1, 0, 0, 0},
	{0, (float)cos(-ROTATE_RAD), -(float)sin(-ROTATE_RAD), 0},
	{0, (float)sin(-ROTATE_RAD), (float)cos(-ROTATE_RAD), 0},
	{0, 0, 0, 1}};
	const t_mat4	mat2 = {{1, 0, 0, 0},
	{0, (float)cos(ROTATE_RAD), -(float)sin(ROTATE_RAD), 0},
	{0, (float)sin(ROTATE_RAD), (float)cos(ROTATE_RAD), 0},
	{0, 0, 0, 1}};
	const t_mat4	mat3 = {{(float)cos(ROTATE_RAD), 0, (float)sin(ROTATE_RAD), 0},
	{0, 1, 0, 0},
	{-(float)sin(ROTATE_RAD), 0, (float)cos(ROTATE_RAD), 0},
	{0, 0, 0, 1}};
	const t_mat4	mat4 = {{(float)cos(-ROTATE_RAD), 0, (float)sin(-ROTATE_RAD), 0},
	{0, 1, 0, 0},
	{-(float)sin(-ROTATE_RAD), 0, (float)cos(-ROTATE_RAD), 0},
	{0, 0, 0, 1}};

	memcpy(mats->rotmy, mat3, sizeof(mat1));
	memcpy(mats->rotpx, mat2, sizeof(mat1));
	memcpy(mats->rotpy, mat4, sizeof(mat1));
	memcpy(mats->rotmx, mat1, sizeof(mat1));
}

void	initialize_rotation_matrix_2(t_mats *mats)
{
	const t_mat4	mat5 = {{(float)cos(-ROTATE_RAD), -(float)sin(-ROTATE_RAD), 0, 0},
	{(float)sin(-ROTATE_RAD), (float)cos(-ROTATE_RAD), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	const t_mat4	mat6 = {{(float)cos(ROTATE_RAD), -(float)sin(ROTATE_RAD), 0, 0},
	{(float)sin(ROTATE_RAD), (float)cos(ROTATE_RAD), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	memcpy(mats->rotmz, mat5, sizeof(mat5));
	memcpy(mats->rotpz, mat6, sizeof(mat6));
}

void	initialize_scale_matrix(t_mats *mats)
{
	const t_mat4	mat1 = {{1 + SCALE_DELTA, 0, 0, 0},
	{0, 1 + SCALE_DELTA, 0, 0},
	{0, 0, 1 + SCALE_DELTA, 0},
	{0, 0, 0, 1}};
	const t_mat4	mat2 = {{1 - SCALE_DELTA, 0, 0, 0},
	{0, 1 - SCALE_DELTA, 0, 0},
	{0, 0, 1 - SCALE_DELTA, 0},
	{0, 0, 0, 1}};

	memcpy(mats->big, mat1, size0f(mat1));
	memcpy(mats->small, mat2, size0f(mat2));	
}

void	TheInitializer(char *filename, t_ctx *ctx)
{
	ctx->filename = filename;
	ctx->fd = -1;
	ctx->width = 0;
	ctx->height = 0;
	ctx->points = NULL;
	ctx->mlx.mlx = NULL;
	ctx->mlx.win = NULL;
	ctx->mlx.img = NULL;
	initialize_isometric_projection_matrix(ctx->affine_matrix);
	initialize_translation_matrices(&ctx->mats);
	initialize_rotation__matrix_1(&ctx->mats);
	initialize_rotation_matrix_2(&ctx->mats);
	initialize_scale_matrix(&ctx->mats);
}

