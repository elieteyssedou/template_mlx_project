/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elie <Elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:06:22 by eteyssed          #+#    #+#             */
/*   Updated: 2016/04/01 21:30:00 by Elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int		ft_color_to_int(t_color color)
{
	int c;

	c = color.r;
	c = c << 8;
	c += color.g;
	c = c << 8;
	c += color.b;
	return (c);
}

void	ft_put_pixel(t_env env, t_coor pix, t_color color)
{
	mlx_pixel_put(env.mlx, env.win, pix.x, pix.y, ft_color_to_int(color));
}

void	ft_put_pixel_img(t_coor pix, t_img* img)
{
	if ((pix.x >= 0 && pix.x <= SIZE_X) && (pix.y >= 0 && pix.y <= SIZE_Y))
		{
			ft_memcpy(&img->data[(pix.y * img->sizeline) + (pix.x * 4)],\
			&img->color, (size_t)(sizeof(int)));
		}
}
