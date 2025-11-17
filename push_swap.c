/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:40 by slambert          #+#    #+#             */
/*   Updated: 2025/11/17 13:47:34 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_input(char **args);
int		check_single_input(char *str);
void	init_stack_a(t_list **list, char **args);
void	init_stack_b_testing(t_list **list);
void	print_list(t_list *list); // remove after testing!
void	print_lists(t_list *list_a, t_list *list_b);
void	init_indices(t_list **list);
size_t	count_nodes(t_list *list);
void	bubble_sort_array(t_node **node_array, size_t size);
void 	fill_out_indices(t_node **node_array, size_t size);
void	print_lists_index(t_list *list_a, t_list *list_b);

int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;

	(void)stack_b;
	if (argc <= 1 || !args)
		return (ft_printf("Error\n"), -1);
	if (!check_input(args))
		return (ft_printf("Error\n"), -1);
	stack_a = NULL; // brauch ich dann nicht mehr wenn init_stack_a
	stack_b = NULL;
	init_stack_a(&stack_a, args);
	// init_stack_b_testing(&stack_b);
	print_lists(stack_a, stack_b);
	// pseudo code og what to do
	// 1. create indices for the list starting at 1
	init_indices(&stack_a);
	ft_printf("printing stacks - INDEX\n");
	print_lists_index(stack_a, stack_b);
	// 2. split the stack in half with N/2, if num < N -> pb ; else ra
	// 3. push all elems but 3 to b (pb)
	// 4. sort 3 on a hardcoded
	// 5. intelligent push backs from b to a
	// sa(&stack_a);
	// print_list(stack_a);
	// ft_printf("\n trying pa\n");
	// pa(&stack_a, &stack_b);
	// ft_printf("printing stack A\n");
	// print_list(stack_a);
	// ft_printf("\nprinting stack B\n");
	// print_list(stack_b);
	// TEST FOR pb
	//pb(&stack_a, &stack_b);
	//print_lists(stack_a, stack_b);
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

// indices starting from 1 bc 0 is the uninitialized value
void	init_indices(t_list **list)
{
	size_t	arr_size;
	size_t	i;
	t_list	*cur;
	t_node	**node_array;

	// create a temporary array of node pointers
	// sort this array by bubble sort
	// fill out indices
	arr_size = count_nodes(*list);
	printf("The array has %zu elements\n", arr_size);
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
	// bubble sort of node_array
	bubble_sort_array(node_array, arr_size);
	fill_out_indices(node_array, arr_size);
}

void fill_out_indices(t_node **node_array, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		node_array[i]->index = i + 1;
		i++;
	}
}

void	bubble_sort_array(t_node **node_array, size_t size)
{
	size_t		i;
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
	int		i;
	int		minus;
	size_t	i;
	t_list	*new;
	t_node	*node_content;
	int		i;
	t_list	*new;
	t_node	*node_content;
	int		i;
	t_list	*new;
	t_node	*node_content;

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
	//why tf is this deleted if i auto format 
	int i;
	t_list * new;
	t_node *node_content;
	
	i = 1;
	while (args[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return ;
		// num_content = malloc(sizeof(int));
		// if (!num_content)
		// {
		// 	free(new);
		// 	return ;
		// }
		node_content = malloc(sizeof(t_node));
		if (!node_content)
		{
			free(new);
			return ;
		}
		// *num_content = ft_atoi(args[i]);
		node_content->value = ft_atoi(args[i]);
		node_content->index = 0;
		// new->content = num_content;
		new->content = node_content;
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
			ft_printf("%d", ((t_node *)list_a->content)->value);
		else
			ft_printf(" ");
		ft_printf(" ");
		if (list_b)
			ft_printf("%d", ((t_node *)list_b->content)->value);
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

void	print_lists_index(t_list *list_a, t_list *list_b)
{
	while (list_a || list_b)
	{
		// ft_printf("%d %d\n", list_a->content, list_b->content);
		if (list_a)
			ft_printf("%d", ((t_node *)list_a->content)->index);
		else
			ft_printf(" ");
		ft_printf(" ");
		if (list_b)
			ft_printf("%d", ((t_node *)list_b->content)->index);
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
