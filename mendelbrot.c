/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mendelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 16:42:50 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 13:22:24 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_loop(t_mem *mem, t_mvar *var)
{
	while (var->y < mem->img_y)
	{
		var->c.r = mem->x1 + (mem->x2 - mem->x1) / mem->img_x * var->x;
		var->c.i = mem->y1 + (mem->y2 - mem->y1) / mem->img_y * var->y;
		var->z.r = 0;
		var->z.i = 0;
		while (var->a < mem->iter_max && var->err == 0)
		{
			var->r = var->z.r;
			var->i = var->z.i;
			var->z.r = (var->r * var->r) - (var->i * var->i) + var->c.r;
			var->z.i = (2 * var->r * var->i) + var->c.i;
			if ((var->z.r * var->z.r + var->z.i * var->z.i) >= var->lim)
				var->err = 1;
			else
				var->a++;
		}
		ft_display(mem, *var);
		var->a = 0;
		var->err = 0;
		var->y++;
	}
}

void	ft_mandelbrot(t_mem *mem)
{
	t_mvar var;

	var.x = 0;
	var.y = 0;
	var.a = 0;
	var.lim = 4;
	var.err = 0;
	while (var.x < mem->img_x)
	{
		ft_mandelbrot_loop(mem, &var);
		var.y = 0;
		var.x++;
	}
}
