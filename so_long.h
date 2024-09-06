/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:33:52 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/03 09:25:45 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 10
# define XPIXEL 60
# define YPIXEL 70
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

typedef struct s_img
{
	void	*img_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_vars
{
	char	**map;
	int		y_map;
	int		x_map;
	int		x_p;
	int		y_p;
	int		p_counter;
	int		e_counter;
	int		c_counter;
	int		move;
	int		check_e;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	player;
	t_img	wall;
	t_img	floor;
	t_img	collect;
	t_img	exit;
}	t_vars;

/*map validation*/
void	valid_ber_file(char *str);
void	open_ber_file(char *str, t_vars *vars);
void	check_positions(t_vars *vars);
void	flood_fill(t_vars *vars, int y, int x, char **temp);
int		check_all_collectible(char **temp);
int		valid_path_checker(t_vars *vars);
void	ft_free(char **temp);
void	map_error(t_vars *vars);
int		rectangular_checker(t_vars *vars);
int		walled_checker(t_vars *vars);
int		composition_checker(t_vars *vars, int y, int x);
void	map_checker(t_vars *vars);
int		valid_map_size(t_vars *vars);
void	line_check(int fd, t_vars *vars);
char	*join_free(char *txt, char *line);
/*image_display*/
void	window_init(t_vars *vars);
void	image_to_window(t_vars *vars, int x, int y);
void	image_init(t_vars *vars);
void	img_info(t_vars *vars);
/*movements and events*/
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
int		end_game(t_vars *vars);
int		key_press_handler(int keycode, t_vars *vars);
void	ft_hook(t_vars *vars);
/*utiles*/
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);
/*get_next_line*/
char	*ft_strchr(const char *string, int c );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
#endif
