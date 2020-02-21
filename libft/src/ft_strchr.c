/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:38:57 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:38:58 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*st;

	i = 0;
	st = (char *)s;
	while (st[i] != '\0')
	{
		if (st[i] == c)
			return (&st[i]);
		i++;
	}
	if (st[i] == c)
		return (&st[i]);
	return (0);
}
