/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:13:47 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/15 09:54:30 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_settings
{
	int				width;
	int				height;
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
	char			*sprite_texture;
	int				ground_color;
	int				sky_color;
}					t_settings;

typedef struct		s_map
{
	char			**content;
	int				lines;
}					t_map;

int					parse_config(int fd, t_settings *settings, t_map *map);
int					parse_resolution(char *line, t_settings *settings);
int					parse_color(char *line, t_settings *settings, int ground);
int					parse_texture(char **split, t_settings *settings);
int					parse_map_line(char *line, t_map *map);

int					validate_map_columns(t_map *map);

int					print_error(char *message);
int					rgbint(int r, int g, int b);
int					is_valid_map_char(char c);

#endif
