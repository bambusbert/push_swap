/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:25:11 by slambert          #+#    #+#             */
/*   Updated: 2025/11/17 15:43:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **head)
{
    t_list *first;
    t_list *second;

    if (!head || !*head || !(*head)->next)
        return;
    first = *head;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *head = second;
}
void sa(t_list **list)
{
    swap(list);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_list **list)
{
    swap(list);
    ft_putstr_fd("sb\n", 1);
}

void ss(t_list **list_a, t_list **list_b)
{
    sa(list_a);
    sb(list_b);
    ft_putstr_fd("ss\n", 1);
}
