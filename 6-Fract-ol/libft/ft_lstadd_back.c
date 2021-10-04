/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:18:15 by ebodart           #+#    #+#             */
/*   Updated: 2020/11/27 22:18:08 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lst;

	if (!alst || !new)
		return ;
	else if (!(*alst))
		*alst = new;
	else
	{
		lst = *alst;
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
}
