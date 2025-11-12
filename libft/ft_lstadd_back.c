/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:44:38 by slambert          #+#    #+#             */
/*   Updated: 2025/11/12 17:50:19 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *curr;
    
	if (!lst || !new)
		return ;
    if (!*lst)
        *lst = new;
    else
	{
        curr = *lst;
        while (curr->next)
            curr = curr->next;
        curr->next = new;
	}
}