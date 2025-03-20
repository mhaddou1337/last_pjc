/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:28:16 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/19 00:52:30 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void ft_tricorn(char *fractol_name)
{
    free(fractol_name);
    t_init data;
    data.f_name = "tricorn";
    init_data(&data);
	data.function = tricorn_pix;
    mlx_hook(data.mlx_window, 17, 0, ft_close, &data);
    mlx_key_hook(data.mlx_window,hook_handler,&data);
	mlx_mouse_hook(data.mlx_window, hook_handler, &data);
    fractol_draw(&data , tricorn_pix);
    mlx_loop(data.mlx_conx);
}