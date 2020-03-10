/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:00:31 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/10 13:52:34 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_widthsign(t_tab *tpf, long int val)
{
	(tpf->fplus == TRUE) ? ft_putchar_fd('+', 1) : 0;
	if (tpf->fprecision == FALSE)
	{
		ft_putnbr_fd(val, 1);
		ft_putnchar_fd(' ', tpf->nbzero, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
	else if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(val, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
	else
	{
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(val, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

void		ft_display_pos(t_tab *tpf, long int val)
{
	if (tpf->widthsign == TRUE)
		ft_widthsign(tpf, val);
	else
	{
		if (tpf->fminus == FALSE)
		{
			ft_putnchar_fd(' ', tpf->nbspace, 1);
			if (tpf->fplus == TRUE)
				ft_putchar_fd('+', 1);
			ft_putnchar_fd('0', tpf->nbzero, 1);
			ft_putnbr_fd(val, 1);
		}
		else
		{
			if (tpf->fplus == TRUE)
				ft_putchar_fd('+', 1);
			ft_putnbr_fd(val, 1);
			ft_putnchar_fd('0', tpf->nbzero, 1);
			ft_putnchar_fd(' ', tpf->nbspace, 1);
		}
	}
}

void		ft_display_neg(t_tab *tpf, long int val)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(-val, 1);
	}
	else
	{
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(-val, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

void		ft_display_x(t_tab *tpf, long val, char *base)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		if (tpf->fdiese == TRUE)
			(base == BASE16LC) ? ft_putstr_fd("0x", 1) : ft_putstr_fd("0X", 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, base);
	}
	else
	{
		if (tpf->fdiese == TRUE)
			(base == BASE16LC) ? ft_putstr_fd("0x", 1) : ft_putstr_fd("0X", 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, base);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

void		ft_display_ui(t_tab *tpf, unsigned int val)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, BASE10);
	}
	else
	{
		(tpf->widthsign == TRUE) ? ft_putnchar_fd('0', tpf->nbzero, 1) : 0;
		ft_putnbr_base(val, BASE10);
		(tpf->widthsign == FALSE) ? ft_putnchar_fd('0', tpf->nbzero, 1) : 0;
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}
