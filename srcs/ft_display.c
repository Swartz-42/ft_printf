/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:40:10 by lrobert           #+#    #+#             */
/*   Updated: 2020/12/21 16:39:59 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_display_pos(t_tab *tpf, long int val)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(val, 1);
	}
	else
	{
		if (tpf->fprecision == TRUE)
		{
			ft_putnchar_fd('0', tpf->nbzero, 1);
			ft_putnbr_fd(val, 1);
			ft_putnchar_fd(' ', tpf->nbspace, 1);
		}
		else
		{
			ft_putnbr_fd(val, 1);
			ft_putnchar_fd('0', tpf->nbzero, 1);
			ft_putnchar_fd(' ', tpf->nbspace, 1);
		}
	}
}

static void	ft_display_neg(t_tab *tpf, long int val)
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
		if (tpf->fprecision == TRUE)
		{
			ft_putchar_fd('-', 1);
			ft_putnchar_fd('0', tpf->nbzero, 1);
			ft_putnbr_fd(-val, 1);
			ft_putnchar_fd(' ', tpf->nbspace, 1);
		}
		else
		{
			ft_putchar_fd('-', 1);
			ft_putnchar_fd('0', tpf->nbzero, 1);
			ft_putnbr_fd(-val, 1);
			ft_putnchar_fd(' ', tpf->nbspace, 1);
		}
	}
}

void		ft_display_x(t_tab *tpf, long val, char *base)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, base);
	}
	else
	{
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
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, BASE10);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

void		ft_display(t_tab *tpf, int val, int sign)
{
	if (sign == 0)
		ft_display_pos(tpf, val);
	else if (sign == 1)
		ft_display_neg(tpf, val);
	else
	{
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(val, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}
