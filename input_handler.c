/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:04:31 by slambert          #+#    #+#             */
/*   Updated: 2025/11/20 14:04:34 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks all arguments, returns 0 if there is a character that is not a number
int	check_input(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!is_digit_or_minus(args[i][j]))
				return (0);
			j++;
		}
		if (!check_single_input(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_single_input(char *str)
{
	int		minus;
	size_t	i;

	i = 0;
	minus = 0;
	if (str[i] == '-')
	{
		minus = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_digit_or_minus(int c)
{
	if (c == '-')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// returns 1 if duplicates are found 0 if not
int	check_list_for_duplicates(t_list *list)
{
	int		*int_arr;
	size_t	i;
	size_t	length;

	length = count_nodes(list);
	int_arr = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		int_arr[i] = ((t_node *)list->content)->value;
		list = list->next;
		i++;
	}
	if (check_array_for_duplicates(int_arr, length))
	{
		free (int_arr);
		return (1);
	}
	else
	{
		free (int_arr);
		return (0);
	}
}

int	check_array_for_duplicates(int *int_arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (int_arr[i] == int_arr[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
