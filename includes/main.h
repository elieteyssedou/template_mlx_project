/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elie <Elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:00:51 by Elie              #+#    #+#             */
/*   Updated: 2016/04/01 23:44:12 by Elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

	#include "libft.h"
	#include "mlx.h"
	#include <stdio.h>

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

	typedef struct	s_actions
	{
		int		update;
	}				t_actions;

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
		void*		mlx;
		void*		win;
		t_img*		img;
		t_actions*	acts;
	}				t_env;

	#include "libmlx.h"

	int key_hook(int key, t_env *env);
	int loop_hook(t_env* env);
	t_img *init_img(void* mlx);
	t_env *init_env();

#endif
