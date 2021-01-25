/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 09:26:39 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/25 09:40:53 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' ||
			c == 'E' || c == 'W');
}

int				is_valid_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int				is_empty(char c)
{
	return (c == 0 || c == ' ');
}