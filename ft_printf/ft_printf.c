/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:22:36 by cbajji            #+#    #+#             */
/*   Updated: 2024/02/20 17:50:00 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char spec, va_list ptr, int *counter)
{
	if (spec == 'c')
		ft_putchar(va_arg(ptr, int), counter);
	else if (spec == 's')
		ft_putstr(va_arg(ptr, char *), counter);
	else if (spec == 'p')
		ft_putadr(va_arg(ptr, void *), counter);
	else if (spec == 'i' || spec == 'd')
		ft_putnbr(va_arg(ptr, int), counter);
	else if (spec == 'u')
		ft_putnbr_uns(va_arg(ptr, unsigned int), counter);
	else if (spec == 'x' || spec == 'X')
		ft_putnbr_hex(va_arg(ptr, unsigned int), spec, counter);
	else if (spec == '%')
		ft_putchar('%', counter);
	else
		ft_putchar(spec, counter);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	ptr;

	i = 0;
	counter = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	va_start(ptr, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			print_format(format[i], ptr, &counter);
		}
		else if (format[i] != '%')
			ft_putchar(format[i], &counter);
		i++;
	}
	va_end(ptr);
	return (counter);
}
