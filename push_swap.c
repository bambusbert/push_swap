/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:40 by slambert          #+#    #+#             */
/*   Updated: 2025/11/19 16:06:48 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1. create indices for the list starting at 1
2. set variable n (median of the stack)
3. chunk sort
4. push all elems to b (pb)
5. intelligent push backs from b to a */
int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		n;

	if (argc <= 1 || !args)
		return (ft_printf("Error\n"), -1);
	if (!check_input(args))
		return (ft_printf("Error\n"), -1);
	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_a(&stack_a, args))
		return (ft_printf("Error\n"), -1);
	init_indices(&stack_a);
	n = count_nodes(stack_a) / 2;
	chunk_sort(&stack_a, &stack_b, count_nodes(stack_a));
	push_stuff_to_b(&stack_a, &stack_b);
	push_stuff_back_to_a(&stack_a, &stack_b);
}

/* 	a. find element with the highest index
	b. find cheapest way to push that element to the top of b (either rb or rrb)
	c. execute either rb or rrb until that element is at the top of b
	d. push that element to a (pa)
	e. repeat from a until stack b is empty */
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

// returns 1 if the element is in the top half and 2 if the element is in the bottom half
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

// pushes all elements from a to b
void	push_stuff_to_b(t_list **stack_a, t_list **stack_b)
{
	int	nodes;

	nodes = count_nodes(*stack_a);
	while (nodes > 0)
	{
		pb(stack_a, stack_b);
		nodes--;
	}
}

// creates separate chunks (depending on the size of the list to be sorted)
void	chunk_sort(t_list **stack_a, t_list **stack_b, int size_stack_a)
{
	size_t	how_many_chunks;
	size_t	current_chunk;
	size_t	size_stack_a_orig;
	int		lower_limit;
	int		upper_limit;
	size_t	chunk_counter;

	size_stack_a_orig = size_stack_a;
	how_many_chunks = calculate_amount_of_chunks(size_stack_a);
	current_chunk = 1;
	chunk_counter = 0;
	while (1)
	{
		if (!*stack_a)
			break ;
		lower_limit = size_stack_a_orig / how_many_chunks * (current_chunk - 1)
			+ 1;
		upper_limit = lower_limit + size_stack_a_orig / how_many_chunks - 1;
		if (((t_node *)(*stack_a)->content)->index >= lower_limit
			&& ((t_node *)(*stack_a)->content)->index <= upper_limit)
		{
			pb(stack_a, stack_b);
			chunk_counter++;
		}
		else
			ra(stack_a);
		if (chunk_counter == size_stack_a_orig / how_many_chunks)
		{
			chunk_counter = 0;
			current_chunk++;
			continue ;
		}
	}
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

// returns 0 if any duplicates are found
int	init_stack_a(t_list **list, char **args)
{
	int		i;
	t_list	*new;
	t_node	*node_content;

	i = 1;
	while (args[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (0);
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
			return (0);
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
	if (check_list_for_duplicates(*list))
		return (0);
	return (1);
}
/*

// this function splits stack a in half. if an element is smaller than N/2 it will be pushed
// to stack_b. otherwise it will be put at the end of stack a (ra)
// THIS IS DEPRECATED now i am using chunk sort instead of that
void	split_stacks(t_list **stack_a, t_list **stack_b, int n)
{
	size_t	size_stack_a;
	size_t	count_operations;

	size_stack_a = count_nodes(*stack_a);
	count_operations = 0;
	//ft_printf("n is %d\n", n);
	while (count_operations < size_stack_a)
	{
		//100 most efficient: 1.25
		//500 most efficient: 1.22
		if (((t_node *)(*stack_a)->content)->index <= n)
			pb(stack_a, stack_b);
		else
		{
			//method 1: rotate to the end of stack a
				- this is more efficient than method 2
			ra(stack_a);
			//method 2: push to stack b and rotate b
			//pb(stack_a, stack_b);
			//rb(stack_b);
		}
		count_operations++;
	}
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
	// TODO failguards
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

void	print_lists(t_list *list_a, t_list *list_b)
{
	while (list_a || list_b)
	{
		// ft_printf("%d %d\n", list_a->content, list_b->content);
		if (list_a)
		{
			ft_printf("%d", ((t_node *)list_a->content)->value);
			// ft_printf("next pointer: %p\n",(t_node *)list_a->next);
		}
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
	ft_printf("a b\n------------------------------------------------------\n");
}

void	print_lists_index(t_list *list_a, t_list *list_b)
{
	while (list_a || list_b)
	{
		// ft_printf("%d %d\n", list_a->content, list_b->content);
		if (list_a)
		{
			ft_printf("%d", ((t_node *)list_a->content)->index);
			// ft_printf("next pointer: %p\n",(t_node *)list_a->next);
		}
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

int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		n;
	int		show_print;

	show_print = 0;
	// ft_printf("argc is %d\n", argc);
	if (argc <= 1 || !args)
		return (ft_printf("Error\n"), -1);
	if (!check_input(args))
		return (ft_printf("Error\n"), -1);
	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_a(&stack_a, args))
		return (ft_printf("Error\n"), -1);
	// ft_printf("input numbers\n");
	if (show_print)
		print_lists(stack_a, stack_b);
	// 1. create indices for the list starting at 1
	init_indices(&stack_a);
	// set variable n (median of the stack)
	n = count_nodes(stack_a) / 2;
	if (show_print)
		ft_printf("STEP 1 - printing stacks - INDEX\n");
	if (show_print)
		print_lists_index(stack_a, stack_b);
	// 2. split the stack in half with N/2, if num < N -> pb ; else ra
	if (show_print)
		ft_printf("\nSTEP 2 - stack splitting OR chunk sort\n");
	// method 1: split stacks in 2. that is very inefficient for 500 numbers
	// split_stacks(&stack_a, &stack_b, n);
	// method 2: chunk sort.
	chunk_sort(&stack_a, &stack_b, count_nodes(stack_a));
	if (show_print)
		ft_printf("-------------------------------------------\n");
	if (show_print)
	{
		ft_printf("printf after stack splitting\n");
		print_lists_index(stack_a, stack_b);
	}
	// 3. push all elems but 3 to b (pb)
	if (show_print)
		ft_printf("\nSTEP 3 - push all elems to b\n");
	push_stuff_to_b(&stack_a, &stack_b);
	if (show_print)
		ft_printf("-------------------------------------------\n");
	if (show_print)
		ft_printf("printf after push_stuff_to_b\n");
	if (show_print)
		print_lists_index(stack_a, stack_b);
	// 4. sort 3 on a hardcoded
	if (show_print)
		ft_printf("\nSTEP 4 - sort max 3 elements\n");
	sort_three_or_less(&stack_a);
	if (show_print)
		ft_printf("-------------------------------------------\n");
	if (show_print)
		ft_printf("printf after swap_three_or_less\n");
	if (show_print)
		print_lists_index(stack_a, stack_b);
	// 5. intelligent push backs from b to a
	if (show_print)
		ft_printf("\nSTEP 5 - intelligent pushbacks to a\n");
	push_stuff_back_to_a(&stack_a, &stack_b);
	if (show_print)
		ft_printf("-------------------------------------------\n");
	if (show_print)
		ft_printf("printf after pushback\n");
	if (show_print)
		print_lists_index(stack_a, stack_b);
	if (show_print)
		ft_printf("\nprintf after pushback AS VALUES\n");
	if (show_print)
		print_lists(stack_a, stack_b);
}
 */