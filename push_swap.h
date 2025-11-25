/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:32 by slambert          #+#    #+#             */
/*   Updated: 2025/11/24 14:51:46 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_node
{
	int				value;
	int				index;
}					t_node;
// size: how many nrs in 1 chunk
typedef struct s_chunk_info
{
	int				size;
	int				total_chunks;
	int				current_chunk;
	int				pushed_count;
	int				cur_lower_limit;
	int				cur_upper_limit;
}					t_chunk_info;

int					check_input(char **args);
void				swap(t_list **head);
void				sa(t_list **list);
void				sb(t_list **list);
void				ss(t_list **list_a, t_list **list_b);
void				push(t_list **list1, t_list **list2);
void				pa(t_list **list1, t_list **list2);
void				pb(t_list **list1, t_list **list2);
void				rotate(t_list **list);
void				ra(t_list **list);
void				rb(t_list **list);
void				rr(t_list **list_a, t_list **list_b);
void				reverse_rotate(t_list **list);
void				rra(t_list **list);
void				rrb(t_list **list);
void				rrr(t_list **list_a, t_list **list_b);
int					init_indices(t_list **list);
size_t				count_nodes(t_list *list);
void				bubble_sort_array(t_node **node_array, size_t size);
void				fill_out_indices(t_node **node_array, size_t size);
int					init_stack_a(t_list **list, char **args);

void				push_stuff_to_b(t_list **stack_a, t_list **stack_b);
void				push_stuff_back_to_a(t_list **stack_a, t_list **stack_b);
t_list				*find_elem_with_highest_index(t_list *stack);
t_list				*find_elem_with_smallest_index(t_list *stack);
void				find_direction_and_rotate(t_list **stack_b,
						t_list *elem_biggest_index);
void				rotation_manager(t_list **stack_b, int count,
						int direction);
int					is_digit_or_minus(int c);
int					check_single_input(char *str);
int					check_list_for_duplicates(t_list *list);
int					check_array_for_duplicates(int *int_arr, size_t size);
void				chunk_sort(t_list **stack_a, t_list **stack_b,
						int size_stack_a);
void				sort_three_or_less(t_list **stack_a);
void				sort_four(t_list **stack_a,
						t_list **stack_b);
void				sort_five(t_list **stack_a,
						t_list **stack_b);						
void				sort_less_than_five_items(t_list **stack_a,
						t_list **stack_b, size_t size);
int					calculate_amount_of_chunks(int size_stack);

void				ft_lstadd_front(t_list **lst, t_list *new);
size_t				ft_putstr_fd(char *s, int fd);
t_list				*ft_lstlast(t_list *lst);
int					ft_atoi_checked(const char *nptr, int *result);
void				ft_lstadd_back(t_list **lst, t_list *new);
size_t				ft_strlen(const char *str);
void				free_stack(t_list **stack);
t_list				*create_new_list_elem(int value);
void				init_chunk_info(t_chunk_info *chunk, int stack_size);
int					is_list_already_sorted(t_list *stack);

#endif