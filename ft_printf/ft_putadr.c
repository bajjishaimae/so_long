/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:10 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/12 11:51:53 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_adr(unsigned long long nb, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(base[nb], counter);
	else
	{
		ft_putnbr_adr((nb / 16), counter);
		ft_putnbr_adr((nb % 16), counter);
	}
}

void	ft_putadr(void *nbr, int *counter)
{
	unsigned long long	nb;

	nb = (unsigned long long)nbr;
	ft_putstr("0x", counter);
	ft_putnbr_adr(nb, counter);
}
