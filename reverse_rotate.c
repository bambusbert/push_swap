/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:08:42 by slambert          #+#    #+#             */
/*   Updated: 2025/11/14 15:31:12 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_list **list)
{
	t_list *last_node;
	t_list *second_to_last_node;

    if (!list || !(*list) || !(*list)->next)
		return;
	second_to_last_node = *list;
	while (second_to_last_node->next->next != NULL)
	{
		second_to_last_node = second_to_last_node->next;
	}
	last_node = second_to_last_node->next;
	second_to_last_node->next = NULL;
	last_node->next = *list;
	*list = last_node;
}

void	rra(t_list **list)
{
	reverse_rotate(list);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **list)
{
	reverse_rotate(list);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_putstr_fd("rrr\n", 1);
}