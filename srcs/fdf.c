/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:24 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/15 20:41:51 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	fdf(char *filename)
{
	t_ctx	ctx;

	init_fdf_context(filename, &ctx);
	check_input_file(&ctx);
	build_map(&ctx);
	render_grid(&ctx);
}
