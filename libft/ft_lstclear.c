/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:19:02 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/14 12:19:30 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*q;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		del(p->content);
		q = p->next;
		free(p);
		p = q;
	}
	*lst = NULL;
}
