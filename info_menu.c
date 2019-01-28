/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   info_menu.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 17:50:32 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 17:58:30 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_info_julia(t_mem *mem)
{
	t_sqrvar	rectangle;
	t_color		color;

	color = ft_create_color(204, 204, 204, 0);
	rectangle = ft_create_rectangle(380, 765, 383, 935);
	ft_draw_rectangle(mem, color, rectangle);
	color = ft_create_color(0, 0, 0, 0);
	rectangle = ft_create_rectangle(450, 805, 650, 925);
	ft_draw_rectangle(mem, color, rectangle);
	ft_draw_jf_axis(mem);
}

void	ft_display_julia_text(t_mem *mem)
{
	mlx_string_put(mem->mlx_ptr, mem->win_ptr, 20, 920, 0xFFFFFF,
		"Julia:          [X]");
	mlx_string_put(mem->mlx_ptr, mem->win_ptr, 400, 760, 0xFFFFFF,
		"Julia factor representation:");
	if (mem->jf_val == 0)
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 460, 850, 0xDF0000,
			"C out of range.");
	else
	{
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 500, 780, 0xFFFFFF,
			"Im(C) = 2");
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 505, 925, 0xFFFFFF,
			"Im(C) = -2");
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 400, 835, 0xFFFFFF,
			"Re(C)");
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 420, 855, 0xFFFFFF, "=");
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 415, 875, 0xFFFFFF,
			"-2");
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 654, 835, 0xFFFFFF,
			"Re(C)");
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 670, 855, 0xFFFFFF, "=");
		mlx_string_put(mem->mlx_ptr, mem->win_ptr, 670, 875, 0xFFFFFF, "2");
	}
}

void	ft_disp_color_infos(t_mem *mem)
{
	char *str;

	str = ft_itoa(mem->color.r);
	mlx_string_put(mem->mlx_ptr, mem->win_ptr, 180, 800, 0xFF0000,
		str);
	if (str)
		free(str);
	str = ft_itoa(mem->color.g);
	mlx_string_put(mem->mlx_ptr, mem->win_ptr, 240, 800, 0x00FF00,
		str);
	if (str)
		free(str);
	str = ft_itoa(mem->color.b);
	mlx_string_put(mem->mlx_ptr, mem->win_ptr, 300, 800, 0x0000FF,
		str);
	if (str)
		free(str);
}

void	ft_display_info_text(t_mem *mem)
{
	char *str;

	str = ft_strjoin("Iterations: ", ft_itoa(mem->iter_max));
	mlx_string_put(mem->mlx_ptr, mem->win_ptr, 20, 760, 0xFFFFFF,
		str);
	free(str);
	mlx_string_put(mem->mlx_ptr, mem->win_ptr, 20, 800, 0xFFFFFF,
		"Color composes: ");
	if (mem->fract_selec == 0)
		mlx_string_put(mem->mlx_ptr,
			mem->win_ptr, 20, 840, 0xFFFFFF, "Mandelbrot:     [X]");
	else
		mlx_string_put(mem->mlx_ptr,
			mem->win_ptr, 20, 840, 0xFFFFFF, "Mandelbrot:     [ ]");
	if (mem->fract_selec == 1)
		mlx_string_put(mem->mlx_ptr,
			mem->win_ptr, 20, 880, 0xFFFFFF, "Burningship:    [X]");
	else
		mlx_string_put(mem->mlx_ptr,
			mem->win_ptr, 20, 880, 0xFFFFFF, "Burningship:    [ ]");
	if (mem->fract_selec == 2)
		ft_display_julia_text(mem);
	else
		mlx_string_put(mem->mlx_ptr,
			mem->win_ptr, 20, 920, 0xFFFFFF, "Julia:          [ ]");
}

void	ft_display_info_back(t_mem *mem)
{
	int		i;
	int		j;
	t_color color;

	i = 750;
	j = 0;
	color = ft_create_color(140, 140, 140, 0);
	if ((100.0 / mem->pt_x <= 2 && 100.0 / mem->pt_x >= -2)
		&& (100.0 / mem->pt_y <= 2 && 100.0 / mem->pt_y >= -2))
		mem->jf_val = 1;
	else
		mem->jf_val = 0;
	while (i < 950)
	{
		while (j < 800)
		{
			if ((i % 2) + (j % 2) == 1)
				ft_put_pixel(mem, color, j, i);
			j++;
		}
		j = 0;
		i++;
	}
	if (mem->fract_selec == 2 && mem->jf_val == 1)
		ft_display_info_julia(mem);
}
