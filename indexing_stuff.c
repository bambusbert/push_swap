/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:54:52 by slambert          #+#    #+#             */
/*   Updated: 2025/11/17 16:50:30 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* indices starting from 1 bc 0 is the uninitialized value
create a temporary array of node pointers
sort this array by bubble sort
fill out indices */
void	init_indices(t_list **list)
{
	size_t	arr_size;
	size_t	i;
	t_list	*cur;
	t_node	**node_array;

	arr_size = count_nodes(*list);
	//printf("The array has %zu elements\n", arr_size);
	node_array = malloc(sizeof(t_node *) * arr_size);
	// if (!node_array)
	// error handling
	i = 0;
	cur = *list;
	while (i < arr_size)
	{
		node_array[i] = (t_node *)cur->content;
		cur = cur->next;
		i++;
	}
	bubble_sort_array(node_array, arr_size);
	fill_out_indices(node_array, arr_size);
    free (node_array);
}

void	bubble_sort_array(t_node **node_array, size_t size)
{
	size_t	i;
	t_node	*temp;

	if (size <= 1)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (node_array[i]->value > node_array[i + 1]->value)
		{
			temp = node_array[i];
			node_array[i] = node_array[i + 1];
			node_array[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	fill_out_indices(t_node **node_array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		node_array[i]->index = i + 1;
		i++;
	}
}

size_t	count_nodes(t_list *list)
{
	size_t	ret;

	ret = 0;
	while (list)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}
