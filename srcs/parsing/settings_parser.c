/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:06:08 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/17 13:08:29 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	parse_resolution(char **split, t_settings *settings)
{
	if (splitlen(split) != 3)
	{
		free_split(split);
		return (print_error("Invalid resolution in .cub file."));
	}
	if (settings->width != 0 || settings->height != 0)
		print_error_exit("Duplicate resolution in .cub file.", 1);
	settings->width = ft_atoi(split[1]);
	if (settings->width > 2559)
		settings->width = 2559;
	settings->height = ft_atoi(split[2]);
	if (settings->height > 1390)
		settings->height = 1390;
	free_split(split);
	if (settings->width <= 0 || settings->height <= 0)
		return (print_error("Invalid resolution in .cub file."));
	return (SUCCESS);
}

int	parse_color_sky(t_settings *settings, char **colorsplit)
{
	if (settings->sky_color != -1)
		print_error_exit("Duplicate sky color in .cub file.", 1);
	settings->sky_color
		= rgbint_chr(colorsplit[0], colorsplit[1],
			colorsplit[2]);
	free_split(colorsplit);
	if (settings->sky_color == -1)
		return (print_error_exit("Invalid sky color in .cub file.", 1));
	return (SUCCESS);
}

int	parse_color(char *line, t_settings *settings, int ground)
{
	char	**colorsplit;

	colorsplit = ft_split(&line[1], ',');
	free(line);
	if (splitlen(colorsplit) != 3)
	{
		free_split(colorsplit);
		return (print_error("Invalid color in .cub file."));
	}
	if (ground)
	{
		if (settings->ground_color != -1)
			print_error_exit("Duplicate ground color in .cub file.", 1);
		settings->ground_color
			= rgbint_chr(colorsplit[0], colorsplit[1],
				colorsplit[2]);
		free_split(colorsplit);
		if (settings->ground_color == -1)
			return (print_error("Invalid ground color in .cub file."));
	}
	else
		parse_color_sky(settings, colorsplit);
	return (SUCCESS);
}
