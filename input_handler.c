/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:04:31 by slambert          #+#    #+#             */
/*   Updated: 2025/11/18 13:10:14 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks all arguments, returns 0 if there is a character that is not a number
// TODO if there are any duplicates -> error
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
	while(str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return 0;
		i++;
	}
	return 1;
}

int is_digit_or_minus(int c)
{
	if (c == '-')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);

}

int check_for_duplicates (t_list * list)
{
    
}