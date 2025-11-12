/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:25:11 by slambert          #+#    #+#             */
/*   Updated: 2025/11/11 17:46:09 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list *list)
{
    int temp;

    if (list->next == NULL)
        return;
    temp = list[0].value;
    list[0].value = list[1].value;
    list[1].value = temp;
}

void sb(t_list *list)
{
    int temp;

    if (list->next == NULL)
        return;
    temp = list[0].value;
    list[0].value = list[1].value;
    list[1].value = temp;
}

void ss(t_list *list_a, t_list *list_b)
{
    sa(list_a);
    sb(list_b);
}

void pa (t_list *list_a, t_list **list_b)
{
    if (!list_b)
        return;
    //alles in list a um 1 nach hinten verschieben
    list_a[0] = *list_b[0];
    *list_b += 1;
}

void pb (t_list **list_a, t_list *list_b)
{
    if (!list_a)
        return;
    list_b[0] = *list_a[0];
    *list_a += 1;
}