/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:31:02 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/12 11:52:11 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *counter)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], counter);
			i++;
		}
	}
}
