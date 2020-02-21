/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:20:45 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 13:59:34 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;
	int		i;

	a = 0;
	b = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (0);
	while (s1[a] != '\0')
		str[i++] = s1[a++];
	while (s2[b] != '\0')
		str[i++] = s2[b++];
	str[i] = '\0';
	return (str);
}
