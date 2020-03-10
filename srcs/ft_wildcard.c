/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:01:00 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/09 14:53:15 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_wildcard_width(t_tab *tpf)
{
	tpf->width = va_arg(tpf->ap, int);
	if (tpf->width < 0)
	{
		tpf->width = -tpf->width;
		tpf->widthsign = TRUE;
	}
}

void	ft_wildcard_prec(t_tab *tpf)
{
	tpf->valprec = va_arg(tpf->ap, int);
	if (tpf->valprec < 0)
	{
		tpf->fprecision = FALSE;
		tpf->valprec = 0;
	}
}

int		ft_wildcard(t_tab *tpf, int i)
{
	if (tpf->fprecision == TRUE)
		ft_wildcard_prec(tpf);
	else
		ft_wildcard_width(tpf);
	return (i + 1);
}
