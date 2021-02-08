/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:15:10 by lbertran          #+#    #+#             */
/*   Updated: 2021/02/04 15:33:22 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_view *view, int x, int y, int color)
{
	char	*dst;

	if (x > view->settings->width || x < 0 || y >= view->settings->height ||
		y < 0)
		return ;
	dst = view->image->addr + (y * view->image->line_len + x *
		(view->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_pixel_color(t_image *image, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}