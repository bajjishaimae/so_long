/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:38:23 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/02 19:35:20 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->y_p - 1][vars->x_p] == '1' ||
		(vars->map[vars->y_p - 1][vars->x_p] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p - 1][vars->x_p] == 'C')
		vars->c_counter--;
	else if (vars->map[vars->y_p - 1][vars->x_p] == 'E' && !vars->c_counter)
		end_game(vars);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p - 1][vars->x_p] = 'P';
	image_to_window(vars, 0, 0);
	vars->y_p--;
	vars->move++;
	ft_printf("Move: %d\n", vars->move);
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->y_p + 1][vars->x_p] == '1' ||
		(vars->map[vars->y_p + 1][vars->x_p] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p + 1][vars->x_p] == 'C')
		vars->c_counter--;
	else if (vars->map[vars->y_p + 1][vars->x_p] == 'E' && !vars->c_counter)
		end_game(vars);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p + 1][vars->x_p] = 'P';
	image_to_window(vars, 0, 0);
	vars->y_p++;
	vars->move++;
	ft_printf("Move: %d\n", vars->move);
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->y_p][vars->x_p - 1] == '1' ||
		(vars->map[vars->y_p][vars->x_p - 1] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p][vars->x_p - 1] == 'C')
		vars->c_counter--;
	else if (vars->map[vars->y_p][vars->x_p - 1] == 'E' && !vars->c_counter)
		end_game(vars);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p][vars->x_p - 1] = 'P';
	image_to_window(vars, 0, 0);
	vars->x_p--;
	vars->move++;
	ft_printf("Move: %d\n", vars->move);
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->y_p][vars->x_p + 1] == '1' ||
		(vars->map[vars->y_p][vars->x_p + 1] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p][vars->x_p + 1] == 'C')
		vars->c_counter--;
	else if (vars->map[vars->y_p][vars->x_p + 1] == 'E' && !vars->c_counter)
		end_game(vars);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p][vars->x_p + 1] = 'P';
	image_to_window(vars, 0, 0);
	vars->x_p++;
	vars->move++;
	ft_printf("Move: %d\n", vars->move);
}
