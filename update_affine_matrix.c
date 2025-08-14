#include "fdf.h"

void	normal_update(t_mat4 corrent, t_mat4 addition)
{
	t_mat4	new_affine_matrix;

	multiply_matrix4x4(new_affine_matrix, addition, corrent);
	memcpy(corrent, new_affine_matrix, sizeof(new_affine_matrix));
}

void	abnormal_update(t_mat4 corrent, t_mat4 addition, t_point base_point)
{
	t_mat4	new_affine_matrix;
	t_mat4	to_origin_matrix;
	t_mat4	off_origin_matrix;

	init_to_origin_matrix(to_origin_matrix, base_point);
	init_off_origin_matrix(off_origin_matrix, base_point);
	multiply_matrix4x4(new_affine_matrix, to_origin_matrix, corrent);
	multiply_matrix4x4(new_affine_matrix, addition, new_affine_matrix);
	multiplu_matrix(new_affine_matrix, off_origin_matrix, new_affine_matrix);
}

void	update_affine_matrix_2(t_ctx *ctx, int keycode)
{
	if (keycode == KEY_EQUAL)
		abnormal_update(ctx->affine_matrix, ctx->mats.small, ctx->base_point);
	else
		return ;
}

void	update_affine_matrix_1(t_ctx *ctx, int keycode)
{
	if (keycode == KEY_ARROW_LEFT)
		normal_update(ctx->affine_matrix, ctx->mats.left);
	else if (keycode == KEY_ARROW_UP)
		normal_update(ctx->affine_matrix, ctx->mats.up);
	else if (keycode == KEY_ARROW_RIGHT)
		normal_update(ctx->affine_matrix, ctx->mats.right);	
	else if (keycode == KEY_ARROW_DOWN)
		normal_update(ctx->affine_matrix, ctx->mats.down);
	else if (keycode == KEY_D)
		abnormal_update(ctx->affine_matrix, ctx->mats.rotmx, ctx->base_point);
	else if (keycode == KEY_F)
		abnormal_update(ctx->affine_matrix, ctx->mats.rotpx, ctx->base_point);
	else if (keycode == KEY_A)
		abnormal_update(ctx->affine_matrix, ctx->mats.rotmy, ctx->base_point);
	else if (keycode == KEY_S)
		abnormal_update(ctx->affine_matrix, ctx->mats.rotpy, ctx->base_point);
	else if (keycode == KEY_W)
		abnormal_update(ctx->affine_matrix, ctx->mats.rotmz, ctx->base_point);
	else if (keycode == KEY_E)
		abnormal_update(ctx->affine_matrix, ctx->mats.rotpz, ctx->base_point);
	else if (keycode == KEY_MINUS)
		abnormal_update(ctx->affine_matrix, ctx->mats.big, ctx->base_point);
	else 
		abnormal_update_affine_matrix_2(ctx, keycode);	
}