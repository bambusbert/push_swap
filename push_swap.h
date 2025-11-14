/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:32 by slambert          #+#    #+#             */
/*   Updated: 2025/11/14 13:31:44 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"

// weg damit weil eh in der libft header
// typedef struct s_list{
//     int value;
//     struct s_list* next;
// } t_list;

void	swap(t_list **head);
void	sa(t_list **list);
void	sb(t_list **list);
void	ss(t_list **list_a, t_list **list_b);
void	push(t_list **list1, t_list **list2);
void	pa(t_list **list1, t_list **list2);
void	pb(t_list **list1, t_list **list2);

#endif