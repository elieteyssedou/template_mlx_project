/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elie <Elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:00:51 by Elie              #+#    #+#             */
/*   Updated: 2016/04/01 18:57:41 by Elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

	#include "libft.h"
	#include "mlx.h"

	# define SIZE_X 1440
	# define SIZE_Y 900
	# define TITLE "RTV1"

	typedef struct	s_coor
	{
		int		x;
		int		y;
	}				t_coor;

	typedef struct	s_color
	{
		char	r;
		char	g;
		char	b;
	}				t_color;

	typedef struct s_img
	{
		void		*img;
		int			bpp;
		int			sizeline;
		int         endian;
		int			color;
		char		*data;
	}				t_img;

	typedef struct	s_env
	{
		void*	mlx;
		void*	win;
		t_img	img;
	}				t_env;

#endif
