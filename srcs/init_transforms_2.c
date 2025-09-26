/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transforms_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:10:17 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:17:41 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	init_to_origin_transform(t_trs *trs)
{
	const t_mat4	mat = {{1, 0, 0, (float)(-IMAGE_WIDTH / 2)},
	{0, 1, 0, (float)(-IMAGE_HEIGHT / 2)},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	ft_memcpy(trs->to_origin, mat, sizeof(mat));
}

void	init_from_origin_transform(t_trs *trs)
{
	const t_mat4	mat = {{1, 0, 0, (float)(IMAGE_WIDTH / 2)},
	{0, 1, 0, (float)(IMAGE_HEIGHT / 2)},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	ft_memcpy(trs->from_origin, mat, sizeof(mat));
}
