/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elie <Elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:53:26 by Elie              #+#    #+#             */
/*   Updated: 2016/04/01 23:42:59 by Elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 49)
		env->acts->update = 1;
	// printf("%d\n", key);
	return(0);
}

void fill_with_white(t_env* env)
{
	int x;
	int y;
	t_coor pix;

	env->img->color = rand();
	x = 0;
	y = 0;
	while(y <= SIZE_Y)
	{
		pix.x = x;
		pix.y = y;
		ft_put_pixel_img(pix, env->img);
		if (x <= SIZE_X)
			x++;
		else
		{
			x = 0;
			y++;
		}
	}
} 

int loop_hook(t_env* env)
{
	if(env->acts->update)
	{
		fill_with_white(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
		env->acts->update = 0;
	}
	return(0);
}

t_actions *init_actions()
{
	t_actions *acts;

	acts = (t_actions *)malloc(sizeof(*acts));
	acts->update = 1;
	return (acts);
}

t_img *init_img(void* mlx)
{
	t_img	*img;
	
	img = (t_img *)malloc(sizeof(*img));
	img->img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sizeline, &img->endian);
	img->color = 0x000000;

	return(img);
}

t_env *init_env()
{
	t_env		*env;
	
	env = (t_env *)malloc(sizeof(*env));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SIZE_X, SIZE_Y, TITLE);
	env->img = init_img(env->mlx);
	env->acts = init_actions();
	return(env);
}

int main()
{
	t_env	*env;

	env = init_env();
	mlx_key_hook(env->win, key_hook, (void *)env);
	mlx_loop_hook(env->mlx, loop_hook, (void *)env);
	mlx_loop(env->mlx);
	return(0);
}
