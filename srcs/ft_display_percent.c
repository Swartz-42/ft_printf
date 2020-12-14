/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:08:41 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:02:44 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_display_percent(t_tab *tpf)
{
	int	nbspace;

	if (tpf->width > 0)
		nbspace = tpf->width - 1;
	else
		nbspace = tpf->width;
	tpf->length += nbspace + 1;
	if (nbspace < 0)
		nbspace = 0;
	if (!tpf->fminus)
	{
		if (tpf->fzero)
			ft_putnchar_fd('0', nbspace, 1);
		else
			ft_putnchar_fd(' ', nbspace, 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ft_putnchar_fd(' ', nbspace, 1);
	}
	return (tpf->length);
}
