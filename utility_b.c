/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:02:59 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/19 01:24:16 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!!str)
	{
		ft_memcpy(str, s1, ft_strlen(s1));
		ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		return (str);
	}
	return (NULL);
}

int	rgb(int red, int green, int blue)
{
	return (red * 256 * 256 + green * 256 + blue);
}

int	hook_handler(int XK, t_init *data)
{
	if (XK == XK_Escape)
		conx_handler(data, 3);
	else if (XK == XK_Left)
		fractol_draw((data->shift_r += SHIFT, data), data->function);
	else if (XK == XK_Right)
		fractol_draw((data->shift_r -= SHIFT, data), data->function);
	else if (XK == XK_Up)
		fractol_draw((data->shift_i += SHIFT, data), data->function);
	else if (XK == XK_Down)
		fractol_draw((data->shift_i -= SHIFT, data), data->function);
	else if (XK == XK_KP_Add)
		fractol_draw((data->iteration += ADD_ITERATION, data), data->function);
	else if (XK == XK_KP_Subtract)
		fractol_draw((data->iteration -= ADD_ITERATION, data), data->function);
	else if (XK == XK_g)
		fractol_draw((data->zoom /= ZOOM, data), data->function);
	else if (XK == XK_h)
		fractol_draw((data->zoom *= ZOOM, data), data->function);
	return (0);
}
