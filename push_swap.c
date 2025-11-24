/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:40 by slambert          #+#    #+#             */
/*   Updated: 2025/11/24 14:35:04 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO check if the input is already a sorted list. if yes,
// display no instructions at all
// TODO hardcoded version for small number of input parameters (2-5)
#include "push_swap.h"

/* 1. create indices for the list starting at 1
2. chunk sort - push elements to b
3. intelligent push backs from b to a */
int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (-1);
	if (argc < 1 || !args)
		return (ft_putstr_fd("Error\n", 2), -1);
	if (!check_input(args))
		return (ft_putstr_fd("Error\n", 2), -1);
	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_a(&stack_a, args))
		return (ft_putstr_fd("Error\n", 2), -1);
	if (!init_indices(&stack_a))
		return (ft_putstr_fd("Error\n", 2), -1);
	if (is_list_already_sorted(stack_a))
		return (0);
	if (count_nodes(stack_a) <= 5)
		sort_less_than_five_items(&stack_a, &stack_b, count_nodes(stack_a));
	else
		chunk_sort(&stack_a, &stack_b, count_nodes(stack_a));
	push_stuff_back_to_a(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

// returns 1 if the list is already sorted and 0 if not.
// if there is only one element, returns 1
int	is_list_already_sorted(t_list *stack)
{
	int	num1;
	int	num2;

	if (stack && !stack->next)
		return (1);
	while (stack && stack->next)
	{
		num1 = ((t_node *)stack->content)->index;
		num2 = ((t_node *)stack->next->content)->index;
		if (num1 > num2)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// returns 0 if any duplicates are found
int	init_stack_a(t_list **list, char **args)
{
	int		i;
	int		atoi_res;
	t_list	*new;

	i = 1;
	while (args[i])
	{
		if (!ft_atoi_checked(args[i], &atoi_res))
			return (free_stack(list), 0);
		new = create_new_list_elem(atoi_res);
		if (!new)
			return (free_stack(list), 0);
		ft_lstadd_back(list, new);
		i++;
	}
	if (check_list_for_duplicates(*list))
		return (free_stack(list), 0);
	return (1);
}

t_list	*create_new_list_elem(int value)
{
	t_node	*node_content;
	t_list	*new_list_elem;

	node_content = malloc(sizeof(t_node));
	if (!node_content)
		return (NULL);
	node_content->value = value;
	node_content->index = 0;
	new_list_elem = malloc(sizeof(t_list));
	if (!new_list_elem)
	{
		free(node_content);
		return (NULL);
	}
	new_list_elem->content = node_content;
	new_list_elem->next = NULL;
	return (new_list_elem);
}

void	free_stack(t_list **stack)
{
	t_list	*current_node;
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp = current_node->next;
		free(current_node->content);
		free(current_node);
		current_node = tmp;
	}
	*stack = NULL;
}

/*

// this function splits stack a in half. if an element is smaller
// than N/2 it will be pushed
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