/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:52:55 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/12 11:52:58 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int nb, int spec, int *counter)
{
	char	*base;

	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(base[nb], counter);
	else
	{
		ft_putnbr_hex((nb / 16), spec, counter);
		ft_putnbr_hex((nb % 16), spec, counter);
	}
}
