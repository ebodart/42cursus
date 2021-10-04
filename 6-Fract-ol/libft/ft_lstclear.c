/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:33:45 by ebodart           #+#    #+#             */
/*   Updated: 2020/12/02 13:58:50 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*liste;
	t_list	*element;

	if (!lst || !del)
		return ;
	liste = *lst;
	while (liste)
	{
		element = liste->next;
		del(liste->content);
		free(liste);
		liste = element;
	}
	*lst = NULL;
}
