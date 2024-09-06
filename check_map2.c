/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:36:12 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/02 19:24:45 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_free(char **temp)
{
	int	y;

	y = 0;
	while (temp[y])
	{
		free(temp[y]);
		y++;
	}
	free(temp);
}

int	check_all_collectible(char **temp)
{
	int	x;
	int	y;

	y = 0;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill(t_vars *vars, int y, int x, char **temp)
{
	if (temp[y][x] == 'X' || temp[y][x] == '1')
		return ;
	if (temp[y][x] == 'E')
	{
		temp[y][x] = 'X';
		vars->check_e++;
		return ;
	}
	else
		temp[y][x] = 'X';
	flood_fill(vars, y + 1, x, temp);
	flood_fill(vars, y - 1, x, temp);
	flood_fill(vars, y, x + 1, temp);
	flood_fill(vars, y, x - 1, temp);
}

void	check_positions(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	vars->move = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x_p = x;
				vars->y_p = y;
			}
			x++;
		}
		y++;
	}
}

int	valid_path_checker(t_vars *vars)
{
	char	**temp;
	int		y;

	y = -1;
	vars->check_e = 0;
	temp = malloc(sizeof(char *) * (vars->y_map + 1));
	if (!temp)
		return (0);
	while (vars->map[++y])
		temp[y] = ft_strdup(vars->map[y]);
	temp[y] = 0;
	check_positions(vars);
	flood_fill(vars, vars->y_p, vars->x_p, temp);
	if (vars->check_e == 0 || !check_all_collectible(temp))
	{
		ft_free(temp);
		return (0);
	}
	ft_free(temp);
	return (1);
}
