/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:14 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/10 13:50:37 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_conversion(t_tab *tpf, int argsize)
{
	if (tpf->fprecision == FALSE && tpf->width > argsize && tpf->fzero == TRUE)
		tpf->nbzero = tpf->width - argsize;
	else if (tpf->width > 0)
		tpf->nbspace = tpf->width - argsize;
	(tpf->nbspace < 0) ? tpf->nbspace = 0 : 0;
	(tpf->nbzero < 0) ? tpf->nbzero = 0 : 0;
	if (tpf->fprecision == TRUE)
	{
		if (tpf->valprec > argsize)
		{
			if (tpf->width > tpf->valprec)
				tpf->nbspace = tpf->width - tpf->valprec;
			else
				tpf->nbspace -= tpf->nbzero;
			tpf->nbzero = tpf->valprec - argsize;
		}
		(tpf->fdiese == TRUE) ? tpf->nbzero += 2 : 0;
		if (tpf->nbspace < 0 || tpf->valprec >= tpf->width)
			tpf->nbspace = 0;
		else if (tpf->valprec <= argsize)
			tpf->nbzero = 0;
		if (tpf->width > argsize + tpf->nbzero)
			tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
	}
}

int			ft_display_hex(char text, t_tab *tpf)
{
	int		argsize;
	long	val;
	char	*base;

	val = va_arg(tpf->ap, long);
	(tpf->widthsign == TRUE) ? tpf->fminus = TRUE : 0;
	base = (text == 'x') ? BASE16LC : BASE16UC;
	argsize = ft_base_ld(val, base);
	if (val != 0 && tpf->fdiese == TRUE)
		argsize = argsize + 2;
	if (val == 0 && tpf->fprecision == TRUE && tpf->valprec == 0)
	{
		argsize = 0;
		if (tpf->width > 0)
			ft_putnchar_fd(' ', tpf->width, 1);
		tpf->nbspace = tpf->width;
		tpf->nbzero = 0;
	}
	else
	{
		ft_conversion(tpf, argsize);
		ft_display_x(tpf, val, base);
	}
	tpf->length += argsize + tpf->nbzero + tpf->nbspace;
	return (tpf->length);
}
