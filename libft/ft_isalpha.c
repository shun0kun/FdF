/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:16:40 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/07 21:46:51 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	if (ft_isalpha(argv[1][0]))
// 		printf("英字です。");
// 	else
// 		printf("英字ではありません。");
// 	return (0);
// }