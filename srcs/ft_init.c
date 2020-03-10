/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:00:38 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/09 15:03:42 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init(t_tab *tpf)
{
	tpf->fminus = FALSE;
	tpf->fzero = FALSE;
	tpf->fprecision = FALSE;
	tpf->fdiese = FALSE;
	tpf->fplus = FALSE;
	tpf->fblank = FALSE;
	tpf->widthsign = FALSE;
	tpf->width = 0;
	tpf->valprec = 0;
	tpf->nbspace = 0;
	tpf->nbzero = 0;
}
