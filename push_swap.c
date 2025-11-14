/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:40 by slambert          #+#    #+#             */
/*   Updated: 2025/11/14 18:20:22 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_input(char **args);
int		check_single_input(char *str);
void	init_stack_a(t_list **list, char **args);
void	init_stack_b_testing(t_list **list);
void	print_list(t_list *list); // remove after testing!
void	print_lists(t_list *list_a, t_list *list_b);

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
	// init_stack_b_testing(&stack_b);
	print_lists(stack_a, stack_b);
	// sa(&stack_a);
	// print_list(stack_a);
	// ft_printf("\n trying pa\n");
	// pa(&stack_a, &stack_b);
	// ft_printf("printing stack A\n");
	// print_list(stack_a);
	// ft_printf("\nprinting stack B\n");
	// print_list(stack_b);
	// TEST FOR pb
	pb(&stack_a, &stack_b);
	print_lists(stack_a, stack_b);
	// ft_printf("\n trying ra\n");
	// ra(&stack_a);
	// ft_printf("printing stack A\n");
	// print_list(stack_a);
	// ft_printf("\nprinting stack B\n");
	// print_list(stack_b);
	// ft_printf("\n trying rra\n");
	// rra(&stack_a);
	// ft_printf("printing stack A\n");
	// print_list(stack_a);
	// ft_printf("\nprinting stack B\n");
	// print_list(stack_b);
}

// checks all arguments, returns 0 if there is a character that is not a number
// TODO -5 is currently an error, that should be fine though
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
			if (args[i][j] < 48 || args[i][j] > 57)
				return (0);
			j++;
		}
		i++;
		// alternative approach:
		/* 		if (!check_single_input(args[i]))
					return (0); */
	}
	return (1);
}
/* 
int	check_single_input(char *str)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	while(str[i])
	{
		if (minus && (str[i] < 48 || str[i] > 57))
			i++;
		else if (str[i] < 48 || str[i] > 57)
	}
} */
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
void	init_stack_b_testing(t_list **list)
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

void	print_lists(t_list *list_a, t_list *list_b)
{
	while (list_a || list_b)
	{
		// ft_printf("%d %d\n", list_a->content, list_b->content);
		if (list_a)
			ft_printf("%d", *((int *)list_a->content));
		else
			ft_printf(" ");
		ft_printf(" ");
		if (list_b)
			ft_printf("%d", *((int *)list_b->content));
		else
			ft_printf(" ");
		ft_printf("\n");
		if (list_a)
			list_a = list_a->next;
		if (list_b)
			list_b = list_b->next;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n------------------------------------------------------");
}

// void	print_list(t_list *list)
// {
// 	size_t i;

// 	i = 0;
// 	while (list)
// 	{
// 		ft_printf("Value of Element %d: %d\n", i, *((int *)list->content));
// 		ft_printf("Pointer of Next Element %d: %p\n", i, list->next);
// 		list = list->next;
// 		i++;
// 	}
// }
