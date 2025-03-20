/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:50:10 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/19 01:44:25 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_pix(int r, int i, t_init *data)
{
	int		color;
	int		iter_nbr;
	double	temp;

	iter_nbr = -1;
	data->z.i = 0.0;
	data->z.r = 0.0;
	data->c.r = scale_number(r, HEI, -2, 2) * data->zoom + data->shift_r;
	data->c.i = scale_number(i, WID, -2, 2) * data->zoom + data->shift_i;
	while (++iter_nbr < data->iteration)
	{
		temp = (data->z.r * data->z.r) - (data->z.i * data->z.i);
		data->z.i = 2 * (data->z.r) * (data->z.i);
		data->z.r = temp;
		data->z.r += data->c.r;
		data->z.i += data->c.i;
		if ((data->z.r * data->z.r + data->z.i * data->z.i) > ESCAPE_VALUER)
		{
			color = 0;
			mlx_pixel_put(data->mlx_conx, data->mlx_window, r, i, color);
			return ;
		}
	}
	mlx_pixel_put(data->mlx_conx, data->mlx_window, r, i, rgb(0, 167, 3));
}

void	tricorn_pix(int r, int i, t_init *data)
{
	int		color;
	int		iter_nbr;
	double	temp;

	iter_nbr = -1;
	data->z.i = 0.0;
	data->z.r = 0.0;
	data->c.r = scale_number(r, HEI, -2, 2) * data->zoom + data->shift_r;
	data->c.i = scale_number(i, WID, -2, 2) * data->zoom + data->shift_i;
	while (++iter_nbr < data->iteration)
	{
		temp = (data->z.r * data->z.r) - (data->z.i * data->z.i);
		data->z.i = -2 * (data->z.r) * (data->z.i);
		data->z.r = temp;
		data->z.r += data->c.r;
		data->z.i += data->c.i;
		if ((data->z.r * data->z.r + data->z.i * data->z.i) > ESCAPE_VALUER)
		{
			color = scale_number(iter_nbr, data->iteration, rgb(14, 14, 14),
					rgb(67, 167, 27));
			mlx_pixel_put(data->mlx_conx, data->mlx_window, r, i, color);
			return ;
		}
	}
	mlx_pixel_put(data->mlx_conx, data->mlx_window, r, i, rgb(167, 164, 0));
}

void	julia_pix(int r, int i, t_init *data)
{
	int		color;
	int		iter_nbr;
	double	temp;

	iter_nbr = -1;
	data->z.r = scale_number(r, HEI, -2, 2) * data->zoom + data->shift_r;
	data->z.i = scale_number(i, WID, -2, 2) * data->zoom + data->shift_i;
	data->c.r = data->julia_r;
	data->c.i = data->julia_i;
	while (++iter_nbr < data->iteration)
	{
		temp = (data->z.r * data->z.r) - (data->z.i * data->z.i);
		data->z.i = 2 * (data->z.r) * (data->z.i);
		data->z.r = temp;
		data->z.r += data->c.r;
		data->z.i += data->c.i;
		if ((data->z.r * data->z.r + data->z.i * data->z.i) > ESCAPE_VALUER)
		{
			color = scale_number(iter_nbr, data->iteration, rgb(14, 14, 14),
					rgb(67, 167, 27));
			mlx_pixel_put(data->mlx_conx, data->mlx_window, r, i, color);
			return ;
		}
	}
	mlx_pixel_put(data->mlx_conx, data->mlx_window, r, i, rgb(255, 145, 0));
}

void	fractol_draw(t_init *data, void (*fractol_pix)(int r, int i, t_init *data))
{
	int	r;
	int	i;

	r = 0;
	while (r < WID)
	{
		i = 0;
		while (i < HEI)
		{
			fractol_pix(r, i, data);
			i++;
		}
		r++;
	}
}
