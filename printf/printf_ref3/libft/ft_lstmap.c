/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwpark <sehwpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:38:04 by sehwpark          #+#    #+#             */
/*   Updated: 2020/12/25 23:25:51 by sehwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*curr;
	t_list	*next;

	if (lst == 0 || !(start = ft_lstnew(f(lst->content))))
		return (0);
	curr = start;
	next = lst->next;
	while (next)
	{
		if (!(curr->next = ft_lstnew(f(next->content))))
		{
			ft_lstclear(&start, del);
			return (0);
		}
		curr = curr->next;
		next = next->next;
	}
	return (start);
}
