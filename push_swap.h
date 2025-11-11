/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:27:32 by slambert          #+#    #+#             */
/*   Updated: 2025/11/11 17:12:13 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "libft/libft.h"

typedef struct s_list{
    int value;
    struct s_list* next;
} t_list;

void sa(t_list *list);
void sb(t_list *list);
void ss(t_list *list_a, t_list *list_b);
void pa (t_list *list_a, t_list **list_b);
void pb (t_list **list_a, t_list *list_b);

#endif