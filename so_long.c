/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:38:59 by cbajji            #+#    #+#             */
/*   Updated: 2024/05/02 20:57:27 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_free(char *txt, char *line)
{
	char	*temp;

	temp = ft_strjoin(txt, line);
	free(txt);
	return (temp);
}

void	line_check(int fd, t_vars *vars)
{
	char	*line;
	char	*txt;

	txt = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			ft_putstr_fd("invalid map!", 2);
			free(txt);
			free(line);
			exit(1);
		}
		txt = join_free(txt, line);
		free(line);
	}
	vars->map = ft_split(txt, '\n');
	free(txt);
}

void	open_ber_file(char *str, t_vars *vars)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error opening the file\n", 2);
		exit (1);
	}
	line_check(fd, vars);
	if (vars->map[0] == 0)
		map_error(vars);
	close (fd);
}

void	valid_ber_file(char *str)
{
	while (*str)
	{
		if (*str == '.' && ft_strcmp(str, ".ber") == 0)
			return ;
		str++;
	}
	ft_putstr_fd("Invalid .ber file\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2 || ac > 2)
	{
		ft_putstr_fd("Please insert 1 argument *.ber file\n", 2);
		exit(1);
	}
	valid_ber_file(av[1]);
	open_ber_file(av[1], &vars);
	map_checker(&vars);
	window_init(&vars);
	image_init(&vars);
	ft_hook(&vars);
	return (0);
}
