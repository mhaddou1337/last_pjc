/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:28:25 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/19 01:43:26 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fractol.h"

double scale_number(double x, double x_max, double y_min, double y_max)
{
    x /= x_max;
    return ((y_max - y_min) * x + y_min);
}
int ft_close(t_init *conx)
{
    mlx_destroy_image(conx->mlx_conx,conx->image.img);
    mlx_destroy_window(conx->mlx_conx,conx->mlx_window);
	mlx_destroy_display(conx->mlx_conx);
	free(conx->mlx_conx);
    free(conx->prog_name);
    exit(0);
}

void ft_mandelbrot(char *fractol_name)
{
    free(fractol_name);
    t_init data;
    data.f_name = "mandelbrot";
	data.function = mandelbrot_pix;
    init_data(&data);
    mlx_hook(data.mlx_window, 17, 0, ft_close, &data);
    mlx_key_hook(data.mlx_window,hook_handler,&data);
	mlx_mouse_hook(data.mlx_window, hook_handler, &data);
    fractol_draw(&data , mandelbrot_pix);
    mlx_loop(data.mlx_conx);
}
