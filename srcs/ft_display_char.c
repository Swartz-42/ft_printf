/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:59:48 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/09 14:54:13 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_display_char(t_tab *tpf)
{
	char	text;
	int		nbspace;

	text = va_arg(tpf->ap, int);
	(tpf->widthsign == TRUE) ? tpf->fminus = TRUE : 0;
	if (tpf->width > 0)
		nbspace = tpf->width - 1;
	else
		nbspace = 0;
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', nbspace, 1);
		ft_putchar_fd(text, 1);
	}
	else
	{
		ft_putchar_fd(text, 1);
		ft_putnchar_fd(' ', nbspace, 1);
	}
	tpf->length += nbspace + 1;
	return (tpf->length);
}
