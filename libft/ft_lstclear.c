/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:58:07 by slambert          #+#    #+#             */
/*   Updated: 2025/11/12 18:03:06 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *cur;
    t_list *next;

    if (lst && del)
    {
        cur = *lst;
        while (cur)
        {
            next = cur->next;
            del(cur->content);
            free(cur);
            cur = next;
        }
        *lst = NULL;
    }
}