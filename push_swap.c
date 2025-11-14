/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:40 by slambert          #+#    #+#             */
/*   Updated: 2025/11/14 15:25:42 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_input(char **args);
void	init_stack_a(t_list **list, char **args);
void	init_stack_b(t_list **list);
void	print_list(t_list *list);

int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;

	(void)stack_b;
	if (argc <= 1 || !args)
		return (ft_printf("Error\n"), -1);
	if (!check_input(args))
		return (ft_printf("Error\n"), -1);
	stack_a = NULL;
	stack_b = NULL;
	init_stack_a(&stack_a, args);
	init_stack_b(&stack_b);
	ft_printf("printing stack A\n");
	print_list(stack_a);
	ft_printf("\nprinting stack B\n");
	print_list(stack_b);
	// sa(&stack_a);
	// print_list(stack_a);
	// ft_printf("\n trying pa\n");
	// pa(&stack_a, &stack_b);
	// ft_printf("printing stack A\n");
	// print_list(stack_a);
	// ft_printf("\nprinting stack B\n");
	// print_list(stack_b);
	// ft_printf("\n trying pb\n");
	// pb(&stack_a, &stack_b);
	// ft_printf("printing stack A\n");
	// print_list(stack_a);
	// ft_printf("\nprinting stack B\n");
	// print_list(stack_b);
	// ft_printf("\n trying ra\n");
	// ra(&stack_a);
	// ft_printf("printing stack A\n");
	// print_list(stack_a);
	// ft_printf("\nprinting stack B\n");
	// print_list(stack_b);
	ft_printf("\n trying rra\n");
	rra(&stack_a);
	ft_printf("printing stack A\n");
	print_list(stack_a);
	ft_printf("\nprinting stack B\n");
	print_list(stack_b);
}

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
			if (args[i][j] < 48 || args[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	init_stack_a(t_list **list, char **args)
{
	size_t	i;
	t_list	*new;
	int		*num_content;

	i = 1;
	while (args[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return ;
		num_content = malloc(sizeof(int));
		if (!num_content)
		{
			free(new);
			return ;
		}
		*num_content = ft_atoi(args[i]);
		new->content = num_content;
		new->next = NULL;
		ft_lstadd_back(list, new);
		i++;
	}
}

// this is for testing, remove later
void	init_stack_b(t_list **list)
{
	size_t	i;
	size_t	j;
	t_list	*new;
	int		*num_content;

	i = 0;
	j = 5;
	while (i < j)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return ;
		num_content = malloc(sizeof(int));
		if (!num_content)
		{
			free(new);
			return ;
		}
		*num_content = i;
		new->content = num_content;
		new->next = NULL;
		ft_lstadd_back(list, new);
		i++;
	}
}

void	print_list(t_list *list)
{
	size_t i;

	i = 0;
	while (list)
	{
		ft_printf("Value of Element %d: %d\n", i, *((int *)list->content));
		ft_printf("Pointer of Next Element %d: %p\n", i, list->next);
		list = list->next;
		i++;
	}
}