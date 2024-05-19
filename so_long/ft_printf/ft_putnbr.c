/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:36:12 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/12 12:44:31 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int nb, int *counter)
{
	if (nb < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-nb, counter);
	}
	else if (nb > 9)
	{
		ft_putnbr((nb / 10), counter);
		ft_putnbr((nb % 10), counter);
	}
	else
		ft_putchar((nb + '0'), counter);
}
