/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:41:23 by slambert          #+#    #+#             */
/*   Updated: 2025/11/20 14:03:57 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stuff_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*elem_biggest_index;

	while (*stack_b)
	{
		elem_biggest_index = find_elem_with_highest_index(*stack_b);
		find_direction_and_rotate(stack_b, elem_biggest_index);
		pa(stack_a, stack_b);
	}
}

t_list	*find_elem_with_highest_index(t_list *stack_b)
{
	int		max;
	t_list	*p_max;

	if (!stack_b)
		return (NULL);
	max = 0;
	p_max = NULL;
	while (stack_b)
	{
		if (((t_node *)stack_b->content)->index > max)
		{
			max = ((t_node *)stack_b->content)->index;
			p_max = stack_b;
		}
		if (stack_b->next)
			stack_b = stack_b->next;
		else
			break ;
	}
	return (p_max);
}

// returns 1 if the element is in the top half
// and 2 if the element is in the bottom half
void	find_direction_and_rotate(t_list **stack_b, t_list *elem_biggest_index)
{
	size_t	length;
	size_t	counter;
	size_t	bottom;
	t_list	*cur;

	length = count_nodes(*stack_b);
	counter = 0;
	cur = *stack_b;
	while (cur != elem_biggest_index)
	{
		cur = cur->next;
		counter++;
	}
	bottom = length - counter;
	if (counter <= bottom)
		rotation_manager(stack_b, counter, 2);
	else
		rotation_manager(stack_b, bottom, 1);
}

void	rotation_manager(t_list **stack_b, int count, int direction)
{
	while (count > 0)
	{
		if (direction == 2)
			rb(stack_b);
		else if (direction == 1)
			rrb(stack_b);
		count--;
	}
}
