/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elie <Elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:53:26 by Elie              #+#    #+#             */
/*   Updated: 2016/04/01 18:47:33 by Elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int loop_hook(t_env* env)
{	
	static int x_ite = 0;
	static int y_ite = 0;

	if (x_ite < SIZE_X)
		x_ite += 15;
	else
	{
		x_ite = 0;
		if (y_ite < SIZE_Y)
			y_ite += 15;
	}
	// mlx_string_put(env->mlx, env->win, x_ite, y_ite, rand(), "<3");
	mlx_string_put(env->mlx, env->win, rand() % SIZE_X, rand() % SIZE_Y, rand(), "<3");
	// mlx_pixel_put(env->mlx, env->win, rand() % SIZE_Y, rand() % SIZE_Y, rand());

	return(0);
}

t_env *init_env(void* mlx, void* win)
{
	t_env	*env;
	
	env = (t_env *)malloc(sizeof(*env));
	env->mlx = mlx;
	env->win = win;

	return(env);
} 

int main()
{
	void	*mlx;
	void	*win;
	t_env	*env;

	mlx = mlx_init();
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, TITLE);
	env = init_env(mlx, win);
	mlx_loop_hook(mlx, loop_hook, env);
	mlx_loop(mlx);
	return(0);
}
