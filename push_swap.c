/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:40 by slambert          #+#    #+#             */
/*   Updated: 2025/11/18 16:57:50 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		check_input(char **args);
// int		check_single_input(char *str);

int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		n;

	//ft_printf("argc is %d\n", argc);
	if (argc <= 1 || !args)
		return (ft_printf("Error1\n"), -1);
	if (!check_input(args))
		return (ft_printf("Error2\n"), -1);
	stack_a = NULL; // brauch ich dann nicht mehr wenn init_stack_a
	stack_b = NULL;
	if (!init_stack_a(&stack_a, args))
		return (ft_printf("Error3\n"), -1);
	//ft_printf("input numbers\n");
	//print_lists(stack_a, stack_b);
	// 1. create indices for the list starting at 1
	init_indices(&stack_a);
	// set variable n (median of the stack)
	n = count_nodes(stack_a) / 2;
	//ft_printf("STEP 1 - printing stacks - INDEX\n");
	//print_lists_index(stack_a, stack_b);
	// 2. split the stack in half with N/2, if num < N -> pb ; else ra
	//ft_printf("\nSTEP 2 - stack splitting\n");
	split_stacks(&stack_a, &stack_b, n);
	//ft_printf("-------------------------------------------\n");
	//ft_printf("printf after stack splitting\n");
	//(stack_a, stack_b);
	// 3. push all elems but 3 to b (pb)
	//ft_printf("\nSTEP 3 - push all elems but 3 to b\n");
	push_stuff_to_b(&stack_a, &stack_b);
	//ft_printf("-------------------------------------------\n");
	//ft_printf("printf after push_stuff_to_b\n");
	//print_lists_index(stack_a, stack_b);
	// 4. sort 3 on a hardcoded
	//ft_printf("\nSTEP 4 - sort max 3 elements\n");
	sort_three_or_less(&stack_a);
	//ft_printf("-------------------------------------------\n");
	//ft_printf("printf after swap_three_or_less\n");
	//print_lists_index(stack_a, stack_b);
	// 5. intelligent push backs from b to a
	//ft_printf("\nSTEP 5 - intelligent pushbacks to a\n");
	push_stuff_back_to_a(&stack_a, &stack_b);
	//ft_printf("-------------------------------------------\n");
	//ft_printf("printf after pushback\n");
	//print_lists_index(stack_a, stack_b);
	//ft_printf("\nprintf after pushback AS VALUES\n");
	//print_lists(stack_a, stack_b);
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
	{
		// a bunch of rb
		// dir = 2
		rotation_manager(stack_b, counter, 2);
	}
	else
	{
		// a bunch of rrb
		// dir = 1
		rotation_manager(stack_b, bottom, 1);
	}
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

// pushes all but 3 elements from a to b
void	push_stuff_to_b(t_list **stack_a, t_list **stack_b)
{
	int	nodes;

	nodes = count_nodes(*stack_a);
	// while (nodes > 3)
	while (nodes > 0)
	{
		pb(stack_a, stack_b);
		nodes--;
	}
}

/* this function splits stack a in half. if an element is smaller than N/2 it will be pushed
to stack_b. otherwise it will be put at the end of stack a (ra)*/
void	split_stacks(t_list **stack_a, t_list **stack_b, int n)
{
	size_t	size_stack_a;
	size_t	count_operations;

	size_stack_a = count_nodes(*stack_a);
	count_operations = 0;
	//ft_printf("n is %d\n", n);
	while (count_operations < size_stack_a)
	{
		if (((t_node *)(*stack_a)->content)->index <= n)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		count_operations++;
	}
}

//returns 0 if any duplicates are found
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
			return 0;
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
			return 0;
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
	if (check_list_for_duplicates (*list))
		return 0;
	return 1;
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

/* // this is for testing, remove later
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
} */