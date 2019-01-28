/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 17:22:18 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:46:33 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_loop(t_mem *mem, t_mvar *var)
{
	while (var->y < mem->img_y)
	{
		var->c.r = 100.0 / (mem->pt_x);
		var->c.i = 100.0 / (mem->pt_y);
		var->z.r = mem->x1 + (mem->x2 - mem->x1) / mem->img_x * var->x;
		var->z.i = mem->y1 + (mem->y2 - mem->y1) / mem->img_y * var->y;
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

void	ft_julia(t_mem *mem)
{
	t_mvar var;

	var.x = 0;
	var.y = 0;
	var.a = 0;
	var.lim = 4;
	var.err = 0;
	while (var.x < mem->img_x)
	{
		ft_julia_loop(mem, &var);
		var.y = 0;
		var.x++;
	}
}
