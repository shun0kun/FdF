/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:01:21 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 15:14:24 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# ifndef INT_MIN
#  define INT_MIN				-2147483648
# endif
# ifndef INT_MAX
#  define INT_MAX				2147483647
# endif

# define WINDOW_WIDTH			1920
# define WINDOW_HEIGHT			1080
# define IMAGE_WIDTH			1920
# define IMAGE_HEIGHT			1080
# define GRID_WIDTH				30
# define GRID_HEIGHT			40
# define GRID_ELEVATION			3

# ifndef M_PI
#  define M_PI				3.14159265358979323846264338327950288
# endif
# define TRANSLATE_PIXEL	5.0f
# define ROTATE_RAD			0.05f
# define SCALE_DELTA		0.1f

# define ISOMETRIC_PROJECTION		0
# define ORTHOGRAPHIC_PROJECTION	1
# define DEFAULT_PROJECTION			ISOMETRIC_PROJECTION

#endif