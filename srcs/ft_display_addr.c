/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:42:49 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/09 16:49:35 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_addrzero(t_tab *tpf, int argsize, unsigned long addr)
{
	if (tpf->fprecision && tpf->valprec == 0 && addr == 0 && tpf->width == 0)
	{
		ft_putstr_fd("0x", 1);
		argsize = 2;
	}
	return (argsize);
}

int			ft_display_addr(t_tab *tpf)
{
	unsigned long	addr;
	int				argsize;

	addr = va_arg(tpf->ap, unsigned long);
	argsize = ft_base(addr, BASE16LC) + 2;
	(tpf->widthsign == TRUE) ? tpf->fminus = TRUE : 0;
	ft_addrzero(tpf, argsize, addr);
	(tpf->width > 0) ? tpf->nbspace = tpf->width - argsize : 0;
	(tpf->nbspace < 0) ? tpf->nbspace = 0 : 0;
	if (tpf->fminus == TRUE)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(addr, BASE16LC);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
	else
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(addr, BASE16LC);
	}
	tpf->length += argsize + tpf->nbspace;
	return (tpf->length);
}
