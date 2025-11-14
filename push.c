/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:05:46 by slambert          #+#    #+#             */
/*   Updated: 2025/11/14 15:02:42 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// take the first element of src and puts it in the beginning (on top) of dest
void	push(t_list **dest, t_list **src)
{
	t_list	*node_to_move;

	if (!src || !(*src))
		return ;
	node_to_move = *src;
    *src = (*src)->next;
    ft_lstadd_front(dest, node_to_move);
}

void	pa(t_list **list_a, t_list **list_b)
{
	if (*list_b)
		push(list_a, list_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **list_a, t_list **list_b)
{
	if (*list_a)
		push(list_b, list_a);
	ft_putstr_fd("pb\n", 1);
}
