/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:17:39 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/07 21:36:38 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	if (ft_isdigit(argv[1][0]))
// 		printf("数字です。");
// 	else
// 		printf("数字ではありません。");
// }