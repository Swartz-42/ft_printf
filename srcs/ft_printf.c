/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:00:53 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/24 17:00:54 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *text, ...)
{
	int		i;
	t_tab	tpf;
	char	*str;

	i = 0;
	va_start(tpf.ap, text);
	tpf.length = 0;
	str = (char *)text;
	while (text[i] != '\0')
	{
		if (text[i] == '%')
		{
			ft_init(&tpf);
			i++;
			i = i + ft_parse(&tpf, str + i);
		}
		else
		{
			ft_putchar_fd(text[i], 1);
			tpf.length++;
			i++;
		}
	}
	va_end(tpf.ap);
	return (tpf.length);
}
