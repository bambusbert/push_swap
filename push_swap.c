/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:40 by slambert          #+#    #+#             */
/*   Updated: 2025/11/11 17:28:20 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_list *list, char **args);
void	init_stack_b(t_list *list);
void	print_array(t_list *list);

int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;

	(void)stack_b;
	if (argc <= 1 || !args)
		return (ft_printf("Error\n"), -1);
	// stack_a = ft_calloc (argc - 1, sizeof(int));
	stack_a = malloc((argc - 1) * sizeof(t_list));
	stack_b = malloc((argc - 1) * sizeof(t_list));
	init_stack_a(stack_a, args);
	init_stack_b(stack_b);
	ft_printf("printing stack A\n");
	print_array(stack_a);
	ft_printf("\nprinting stack B\n");
	print_array(stack_b);
    ft_printf("\nsa\n");
	sa(stack_a);
	print_array(stack_a);
    ft_printf("\npa\n");
	pa(stack_a, &stack_b);
    ft_printf("printing stack A\n");
	print_array(stack_a);
    ft_printf("\nprinting stack B\n");
	print_array(stack_b);
}

void	init_stack_a(t_list *list, char **args)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (args[j])
		j++;
	j--;
	printf("no of arguments: %zu\n", j);
	i = 0;
	while (i < j)
	{
		list[i].value = atoi(args[i + 1]);
		if (i < j - 1)
			list[i].next = &list[i + 1];
		else
			list[i].next = NULL;
		i++;
	}
}

// this is for testing, remove later
void	init_stack_b(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = 5;
	while (i < j)
	{
		list[i].value = i;
		if (i < j - 1)
			list[i].next = &list[i + 1];
		else
			list[i].next = NULL;
		i++;
	}
}

void	print_array(t_list *list)
{
	size_t i;

	i = 0;
	// if (list[0].value && !list[i].next)
	// {
	//     ft_printf("Value of Element %d: %d\n", i, list[i].value);
	//     ft_printf("Pointer of Element %d: %p\n", i, list[i].next);
	// }
	while (list[i].next)
	{
		ft_printf("Value of Element %d: %d\n", i, list[i].value);
		ft_printf("Pointer of Element %d: %p\n", i, list[i].next);
		i++;
	}
	ft_printf("Value of Element %d: %d\n", i, list[i].value);
	ft_printf("Pointer of Element %d: %p\n", i, list[i].next);
}