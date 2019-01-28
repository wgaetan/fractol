/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 16:05:03 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 15:25:27 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int			ft_usage(void)
{
	ft_putstr("Wrong argument\n");
	ft_putstr("Usage: ./fractol [fractal at launch]\n");
	ft_putstr("Available fractals -> Mandelbrot / Burningship / Julia\n");
	return (0);
}

int			ft_parse_arg(char *str)
{
	int ret;

	if (ft_strcmp("Mandelbrot", str) == 0)
		ret = 0;
	else if (ft_strcmp("Burningship", str) == 0)
		ret = 1;
	else if (ft_strcmp("Julia", str) == 0)
		ret = 2;
	else
		ret = -1;
	return (ret);
}

void		ft_print_loop(t_mem *mem)
{
	ft_create_img(mem);
	ft_color_check(mem);
	if (mem->fract_selec == 0)
		ft_mandelbrot(mem);
	if (mem->fract_selec == 1)
		ft_burningship(mem);
	if (mem->fract_selec == 2)
		ft_julia(mem);
	if (mem->menu_tgl == 1)
		ft_display_info_back(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win_ptr, mem->img.ptr, 0, 0);
	if (mem->menu_tgl == 1)
		ft_display_info_text(mem);
	if (mem->menu_tgl == 1)
		ft_disp_color_infos(mem);
}

static void	ft_init_mem(t_mem *mem, char *arg)
{
	mem->img_x = 1000.0;
	mem->img_y = mem->img_x;
	mem->x_offset = 0;
	mem->y_offset = 0;
	mem->iter_max = 10;
	mem->x_inflim = -2.4;
	mem->x_suplim = 2.4;
	mem->y_inflim = -2.4;
	mem->y_suplim = 2.4;
	mem->zoom = 2;
	mem->menu_tgl = 1;
	mem->color.r = 255;
	mem->color.g = 30;
	mem->color.b = 100;
	mem->color.t = 0;
	mem->julia_dynam = 0;
	mem->color_dynam = 0;
	if ((mem->fract_selec = ft_parse_arg(arg)) == -1)
	{
		free(mem);
		ft_usage();
		exit(0);
	}
}

int			main(int argc, char **argv)
{
	t_mem	*mem;

	if (argc != 2)
		return (ft_usage());
	dprintf(1, "%b", PointerMotionMask);
	mem = (t_mem *)malloc(sizeof(t_mem));
	ft_init_mem(mem, argv[1]);
	mem->x1 = mem->x_inflim;
	mem->x2 = mem->x_suplim;
	mem->y1 = mem->y_inflim;
	mem->y2 = mem->y_suplim;
	mem->mlx_ptr = mlx_init();
	mem->win_ptr = mlx_new_window(mem->mlx_ptr,
		(int)mem->img_x, (int)mem->img_y, "fract'ol");
	ft_print_loop(mem);
	mlx_key_hook(mem->win_ptr, ft_key, (void *)mem);
	mlx_mouse_hook(mem->win_ptr, ft_mouse, (void *)mem);
	mlx_hook(mem->win_ptr, 6, 1L << 6, ft_mouse_motion, (void *)mem);
	mlx_loop(mem->mlx_ptr);
}
