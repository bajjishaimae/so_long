/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:43:45 by cbajji            #+#    #+#             */
/*   Updated: 2023/12/12 12:44:37 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, int *counter);
void	ft_putadr(void *nbr, int *counter);
void	ft_putnbr_hex(unsigned int nb, int spec, int *counter);
void	ft_putnbr_uns(unsigned int nb, int *counter);
void	ft_putnbr(long int nb, int *counter);
void	ft_putstr(char *str, int *counter);
int		ft_printf(const char *format, ...);

#endif