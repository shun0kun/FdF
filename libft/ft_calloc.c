/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:03:44 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/07 20:52:36 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
	return (p);
}

/*１つ目のifの条件式はn * s < maxの必要十分条件。場合分けして考えればわかるよ。5バイトのはこを10個入れたいって考えると直感的に理解できる*/