/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:56 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/26 14:53:27 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	f(t_trs trs, t_mat4 mat, t_mat4 model, t_mat4 res)
{
	multiply_matrix4x4(trs.to_origin, model, model);
	multiply_matrix4x4(mat, model, model);
	multiply_matrix4x4(trs.from_origin, model, res);
}

void	update_model(t_mat4 model, t_trs trs, int keycode)
{
	if (keycode == KEY_ARROW_LEFT)
		multiply_matrix4x4(trs.translate_left, model, model);
	else if (keycode == KEY_ARROW_UP)
		multiply_matrix4x4(trs.translate_up, model, model);
	else if (keycode == KEY_ARROW_RIGHT)
		multiply_matrix4x4(trs.translate_right, model, model);
	else if (keycode == KEY_ARROW_DOWN)
		multiply_matrix4x4(trs.translate_down, model, model);
	else if (keycode == KEY_D)
		f(trs, trs.rotate_x_plus, model, model);
	else if (keycode == KEY_F)
		f(trs, trs.rotate_x_minus, model, model);
	else if (keycode == KEY_A)
		f(trs, trs.rotate_y_plus, model, model);
	else if (keycode == KEY_S)
		f(trs, trs.rotate_y_minus, model, model);
	else if (keycode == KEY_W)
		f(trs, trs.rotate_z_plus, model, model);
	else if (keycode == KEY_E)
		f(trs, trs.rotate_z_minus, model, model);
	else if (keycode == KEY_EQUAL)
		f(trs, trs.scale_up, model, model);
	else if (keycode == KEY_MINUS)
		f(trs, trs.scale_down, model, model);
}
