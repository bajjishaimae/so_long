/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:37:34 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/12 11:52:06 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uns(unsigned int nb, int *counter)
{
	if (nb > 9)
	{
		ft_putnbr_uns((nb / 10), counter);
		ft_putnbr_uns((nb % 10), counter);
	}
	else
		ft_putchar((nb + '0'), counter);
}
