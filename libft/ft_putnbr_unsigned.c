/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slambert <slambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:08:29 by slambert          #+#    #+#             */
/*   Updated: 2025/11/10 15:32:02 by slambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr_fd_unsigned(fd, n / 10);
	}
	i += ft_putchar_fd(fd, n % 10 + '0');
	return (i);
}
