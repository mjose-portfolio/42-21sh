/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose <mjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 03:05:53 by mjose             #+#    #+#             */
/*   Updated: 2019/04/16 03:06:01 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *el, int free_content)
{
	t_list	*tmpelement;

	if (el)
	{
		if (el->prev)
			el->prev->next = el->next ? el->next : NULL;
		if (el->next)
		{
			el->next->prev = el->prev ? el->prev : NULL;
			tmpelement = el->next;
			while (tmpelement)
			{
				tmpelement->index--;
				tmpelement = tmpelement->next;
			}
		}
		if (el->content && free_content)
			ft_free(el->content);
		ft_free(el);
	}
}
