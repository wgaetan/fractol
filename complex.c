/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   complex.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 13:11:21 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 12:51:26 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_comp_multi(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.r = (a.r * b.r) - (a.i * b.i);
	ret.i = (a.r * b.i) + (b.r * a.i);
	return (ret);
}

t_complex	ft_comp_add(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.r = a.r + b.r;
	ret.i = a.i + b.i;
	return (ret);
}

t_complex	ft_comp_pow(t_complex a, int b)
{
	t_complex	ret;
	t_complex	tmp;

	ret = a;
	while (b > 1)
	{
		tmp.r = (a.r * ret.r) - (a.i * ret.i);
		tmp.i = (a.r * ret.i) + (ret.r * a.i);
		ret = tmp;
		b--;
	}
	return (ret);
}
