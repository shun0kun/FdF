/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimotsukasashunsuke <shimotsukasashuns    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:53:24 by sshimots          #+#    #+#             */
/*   Updated: 2025/08/17 16:17:01 by shimotsukas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/fdf.h"

void	fdf(char *filename)
{
	t_ctx	ctx;

	init_fdf_context(filename, &ctx);
	if (!is_valid_file(filename))
		cleanip_context("Invalid file\n", &ctx);
	build_map(&ctx);
	render_grid(&ctx);
}
