/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:28:16 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/21 22:37:20 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
//int 
void ft_tricorn(char *fractol_name)
{
    free(fractol_name);
    t_init data;
    data.f_name = "tricorn";
    init_data(&data);
	data.function = tricorn_pix;
    mlx_hook(data.mlx_window, 17, 0, ft_close, &data);
    mlx_hook(data.mlx_window, 2, 1,key_handler,&data); 
	mlx_mouse_hook(data.mlx_window, mouse_handler, &data);
    fractol_draw(&data , tricorn_pix);
    mlx_loop(data.mlx_conx);
}