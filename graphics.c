/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:31:07 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/03 12:45:07 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map_size(t_vars *vars)
{
	if (vars->x_map >= 118 || vars->y_map >= 118)
		return (0);
	return (1);
}

void	image_to_window(t_vars *vars, int x, int y)
{
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->floor.img_ptr, x * XPIXEL, y * YPIXEL);
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->wall.img_ptr, x * XPIXEL, y * YPIXEL);
			if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->player.img_ptr, x * XPIXEL, y * YPIXEL);
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->exit.img_ptr, x * XPIXEL, y * YPIXEL);
			if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->collect.img_ptr, x * XPIXEL, y * YPIXEL);
			x++;
		}
		y++;
	}
}

void	img_info(t_vars *vars)
{
	vars->player.x = 60;
	vars->player.y = 70;
	vars->floor.x = 60;
	vars->floor.y = 70;
	vars->collect.x = 60;
	vars->collect.y = 70;
	vars->exit.x = 60;
	vars->exit.y = 70;
	vars->wall.x = 60;
	vars->wall.y = 70;
}

void	image_init(t_vars *vars)
{
	vars->player.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./xpm/player.xpm", &vars->player.x, &vars->player.y);
	vars->wall.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./xpm/wall.xpm", &vars->wall.x, &vars->wall.y);
	vars->collect.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./xpm/collect.xpm", &vars->collect.x, &vars->collect.y);
	vars->floor.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./xpm/floor.xpm", &vars->floor.x, &vars->floor.y);
	vars->exit.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
			"./xpm/exit.xpm", &vars->exit.x, &vars->exit.y);
	if (!(vars->player.img_ptr) || !(vars->wall.img_ptr)
		|| !(vars->collect.img_ptr) || !(vars->floor.img_ptr)
		|| !(vars->exit.img_ptr))
	{
		ft_putstr_fd("error in image", 2);
		exit(1);
	}
	image_to_window(vars, 0, 0);
}

void	window_init(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->x_map * XPIXEL,
			vars->y_map * YPIXEL, "so_long");
	return ;
}
