/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:47:08 by slambert          #+#    #+#             */
/*   Updated: 2025/11/17 15:08:01 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shifts all elements up. 
void	rotate(t_list **list)
{
    t_list *first_node;
    t_list* last_node;

    if (!list || !(*list) || !(*list)->next)
        return;
    first_node = *list;
    last_node = ft_lstlast(*list);
    *list = (*list)->next;
    last_node->next = first_node;
    first_node->next = NULL;
}

void	ra(t_list **list)
{
    rotate(list);
	ft_putstr_fd("\nra\n", 1);
}

void	rb(t_list **list)
{
    rotate(list);
	ft_putstr_fd("\nrb\n", 1);
}

void	rr(t_list **list_a, t_list** list_b)
{
    rotate(list_a);
    rotate(list_b);
	ft_putstr_fd("\nrr\n", 1);
}