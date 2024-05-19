/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:37:06 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/02 19:35:06 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_vars *vars)
{
	ft_free(vars->map);
	mlx_destroy_image(vars->mlx_ptr, vars->player.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->wall.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->exit.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->collect.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->floor.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	ft_putstr_fd("Success!\n", 1);
	exit (0);
	return (1);
}

int	key_press_handler(int keycode, t_vars *vars)
{
	if (keycode == 13)
		move_up(vars);
	else if (keycode == 0)
		move_left(vars);
	else if (keycode == 1)
		move_down(vars);
	else if (keycode == 2)
		move_right(vars);
	else if (keycode == 53)
		end_game(vars);
	return (1);
}

void	ft_hook(t_vars *vars)
{
	ft_printf("Move: 0\n");
	mlx_hook(vars->win_ptr, 2, 0, key_press_handler, vars);
	mlx_hook(vars->win_ptr, 17, 0, end_game, vars);
	mlx_loop(vars->mlx_ptr);
}
