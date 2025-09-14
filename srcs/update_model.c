#include "internal/fdf.h"

void	f(t_transforms transforms, t_mat4 transform, t_mat4 model, t_mat4 res)
{
	multiply_matrix4x4(transforms.to_origin, model, model);
	multiply_matrix4x4(transform, model, model);
	multiply_matrix4x4(transforms.from_origin, model, res);//3つ目の引数はmodelでも結果は同じ。
}

void	update_model(t_mat4 model, t_transforms transforms, int keycode)
{
	if (keycode == KEY_ARROW_LEFT)
		multiply_matrix4x4(transforms.translate_left, model, model);
	if (keycode == KEY_ARROW_UP)
		multiply_matrix4x4(transforms.translate_up, model, model);
	if (keycode == KEY_ARROW_RIGHT)
		multiply_matrix4x4(transforms.translate_right, model, model);
	if (keycode == KEY_ARROW_DOWN)
		multiply_matrix4x4(transforms.translate_down, model, model);
	if (keycode == KEY_D)
		f(transforms, transforms.rotate_x_plus, model, model);
	if (keycode == KEY_F)
		f(transforms, transforms.rotate_x_minus, model, model);
	if (keycode == KEY_A)
		f(transforms, transforms.rotate_y_plus, model, model);
	if (keycode == KEY_S)
		f(transforms, transforms.rotate_y_minus, model, model);
	if (keycode == KEY_W)
		f(transforms, transforms.rotate_z_plus, model, model);
	if (keycode == KEY_E)
		f(transforms, transforms.rotate_z_minus, model, model);
	if (keycode == KEY_EQUAL)
		f(transforms, transforms.scale_up, model, model);
	if (keycode == KEY_MINUS)
		f(transforms, transforms.scale_down, model, model);
}