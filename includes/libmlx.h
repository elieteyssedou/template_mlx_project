/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elie <Elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:29:56 by Elie              #+#    #+#             */
/*   Updated: 2016/04/01 21:22:30 by Elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

	t_color	ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b);
	int		ft_color_to_int(t_color color);
	void	ft_put_pixel(t_env env, t_coor point, t_color color);
	void	ft_put_pixel_img(t_coor point, t_img *img);

#endif
