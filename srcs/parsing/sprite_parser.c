/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:18:48 by lbertran          #+#    #+#             */
/*   Updated: 2021/02/22 14:43:37 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_sprite(int x, int y, t_view *view, int type)
{
	t_sprite	sprite;

	if (view->sprites == NULL)
		view->sprites = malloc(sizeof(t_sprite) *
		(view->map->lines * view->map->longest));
	sprite.pos_x = x + 0.5;
	sprite.pos_y = y + 0.5;
	sprite.type = type - 2;
	sprite.order = view->sprite_count;
	sprite.visible = TRUE;
	view->sprites[sprite.order] = sprite;
	view->sprite_count++;
}
