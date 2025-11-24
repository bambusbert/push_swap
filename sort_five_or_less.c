/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:33:54 by slambert          #+#    #+#             */
/*   Updated: 2025/11/24 14:35:27 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_than_five_items(t_list **stack_a, t_list **stack_b,
		size_t size)
{
	if (size <= 3)
		sort_three_or_less(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
	if (size == 5)
		sort_five(stack_a, stack_b);
}

void	sort_three_or_less(t_list **stack_a)
{
	int	top;
	int	mid;
	int	btm;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	mid = 0;
	btm = 0;
	top = ((t_node *)((*stack_a)->content))->index;
	if ((*stack_a)->next)
		mid = ((t_node *)((*stack_a)->next->content))->index;
	if ((*stack_a)->next->next)
		btm = ((t_node *)((*stack_a)->next->next->content))->index;
	if (top > mid && top > btm)
		ra(stack_a);
	else if (mid > top && mid > btm)
		rra(stack_a);
	top = ((t_node *)((*stack_a)->content))->index;
	mid = ((t_node *)((*stack_a)->next->content))->index;
	if (top > mid)
		sa(stack_a);
}

/* find smallest number, push to b. with the remaining 3 on
a: sort_three. last step: push smallest element from b to a */
void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_elem;

	smallest_elem = find_elem_with_smallest_index(*stack_a);
	if (smallest_elem == (*stack_a)->next)
		sa(stack_a);
	else if (smallest_elem == (*stack_a)->next->next)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (smallest_elem == (*stack_a)->next->next->next)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three_or_less(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_elem;

	smallest_elem = find_elem_with_smallest_index(*stack_a);
	if (smallest_elem == (*stack_a)->next)
		sa(stack_a);
	else if (smallest_elem == (*stack_a)->next->next)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (smallest_elem == (*stack_a)->next->next->next)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (smallest_elem == (*stack_a)->next->next->next->next)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
