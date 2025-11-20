/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:37:41 by slambert          #+#    #+#             */
/*   Updated: 2025/11/20 14:03:40 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_list **stack_a, t_list **stack_b, int size_stack_a)
{
	t_chunk_info	chunk;
	int				idx;

	init_chunk_info(&chunk, size_stack_a);
	while (1)
	{
		if (!*stack_a)
			break ;
		chunk.cur_lower_limit = chunk.size * (chunk.current_chunk - 1) + 1;
		chunk.cur_upper_limit = chunk.cur_lower_limit + chunk.size - 1;
		idx = ((t_node *)(*stack_a)->content)->index;
		if (idx >= chunk.cur_lower_limit && idx <= chunk.cur_upper_limit)
		{
			pb(stack_a, stack_b);
			chunk.pushed_count++;
		}
		else
			ra(stack_a);
		if (chunk.pushed_count >= chunk.size)
		{
			chunk.pushed_count = 0;
			chunk.current_chunk++;
		}
	}
}

void	init_chunk_info(t_chunk_info *chunk, int stack_size)
{
	chunk->total_chunks = calculate_amount_of_chunks(stack_size);
	if (chunk->total_chunks > 0)
		chunk->size = stack_size / chunk->total_chunks;
	else
		chunk->size = stack_size;
	chunk->current_chunk = 1;
	chunk->pushed_count = 0;
}

// for 500 numbers 12-14 is most efficient
// for 100 numbers 4-6 is most efficient
int	calculate_amount_of_chunks(int size_stack)
{
	if (size_stack <= 0)
		return (0);
	if (size_stack >= 1 && size_stack <= 9)
		return (1);
	if (size_stack >= 10 && size_stack <= 19)
		return (2);
	if (size_stack >= 20 && size_stack <= 49)
		return (3);
	if (size_stack >= 50 && size_stack <= 99)
		return (5);
	if (size_stack >= 100 && size_stack <= 199)
		return (6);
	if (size_stack >= 200 && size_stack <= 299)
		return (8);
	if (size_stack >= 300 && size_stack <= 499)
		return (10);
	if (size_stack >= 500 && size_stack <= 699)
		return (12);
	if (size_stack >= 700 && size_stack <= 999)
		return (14);
	if (size_stack >= 700 && size_stack <= 999)
		return (14);
	return (16);
}
