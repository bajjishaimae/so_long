/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:35:18 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/02 21:05:04 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_vars *vars)
{
	ft_free(vars->map);
	ft_putstr_fd("Invalid map\n", 2);
	exit (1);
}

int	composition_checker(t_vars *vars, int y, int x)
{
	while (vars->map[y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] != '1' && vars->map[y][x] != '0' &&
					vars->map[y][x] != 'P' && vars->map[y][x] != 'E' &&
						vars->map[y][x] != 'C')
				return (0);
			if (vars->map[y][x] == 'P')
				vars->p_counter++;
			else if (vars->map[y][x] == 'E')
				vars->e_counter++;
			else if (vars->map[y][x] == 'C')
				vars->c_counter++;
			x++;
		}
		x = 0;
		y++;
	}
	if (vars->p_counter > 1 || vars->e_counter > 1 || vars->c_counter == 0
		|| vars->p_counter == 0)
		return (0);
	return (1);
}

int	walled_checker(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map[0][x] && vars->map[vars->y_map - 1][x])
	{
		if (vars->map[0][x] != '1' || vars->map[vars->y_map - 1][x] != '1')
			return (0);
		x++;
	}
	while (vars->map[y])
	{
		if (vars->map[y][0] != '1' || vars->map[y][vars->x_map - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	rectangular_checker(t_vars *vars)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(vars->map[0]);
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x + 1] == '\0')
			{
				if (x + 1 != len)
					return (0);
			}
			x++;
		}
		y++;
	}
	vars->x_map = len;
	vars->y_map = y;
	return (1);
}

void	map_checker(t_vars *vars)
{
	vars->c_counter = 0;
	vars->p_counter = 0;
	vars->e_counter = 0;
	if (!rectangular_checker(vars) || !walled_checker(vars)
		|| !composition_checker(vars, 0, 0) || !valid_path_checker(vars)
		|| !valid_map_size(vars))
		map_error(vars);
	return ;
}
