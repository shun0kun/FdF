/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:19:25 by sshimots          #+#    #+#             */
/*   Updated: 2025/05/14 15:25:05 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_nodefree(t_list *node, void (*del)(void *))
// {
// 	t_list	*p;

// 	while (node)
// 	{
// 		p = node;
// 		del(p->content);
// 		free(p);
// 		node = node->next;
// 	}
// 	return (NULL);
// }

void	*ft_nodeclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*q;

	if (!lst || !del)
		return (NULL);
	p = *lst;
	while (p)
	{
		del(p->content);
		q = p->next;
		free(p);
		p = q;
	}
	*lst = NULL;
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*first_node;

	if (!lst || !f || !del)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	first_node = node;
	while (lst)
	{
		node->content = f(lst->content);
		if (!lst->next)
		{
			node->next = NULL;
			break ;
		}
		node->next = malloc(sizeof(t_list));
		if (!node->next)
			return (ft_nodeclear(&first_node, del));
		node = node->next;
		lst = lst->next;
	}
	return (first_node);
}

//ft_lstadd_back.cをつかって、newを作ってから後ろにくっつける方式でもいい。