/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:47:56 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/21 18:29:40 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "../libft/include/libft.h"

enum			e_boolean
{
	TRUE = 1,
	FALSE = 0
};

typedef struct	s_tab
{
	enum e_boolean	fminus;
	enum e_boolean	fzero;
	enum e_boolean	fprecision;
	int				width;
	int				valprec;
	int				length;
	int				nbspace;
	int				nbzero;
	va_list			ap;
}				t_tab;

#define BASE10 "0123456789"
#define	BASE16LC "0123456789abcdef"
#define	BASE16UC "0123456789ABCDEF"

int				ft_printf(const char *text, ...)
				__attribute__((format(printf, 1, 2)));
int				ft_display_int(t_tab *tpf);
int				ft_display_u_int(t_tab *tpf);
int				ft_display_str(t_tab *tpf);
int				ft_display_percent(t_tab *tpf);
int				ft_display_hex(char text, t_tab *tpf);
int				ft_display_char(t_tab *tpf);
int				ft_display_addr(t_tab *tpf);
void			ft_display(t_tab *tpf, int val, int sign);
void			ft_display_x(t_tab *tpf, long val, char *base);
void			ft_display_ui(t_tab *tpf, unsigned int val);
void			ft_init(t_tab *tpf);
int				ft_parse(t_tab *tpf, char *str);
void			ft_precision_neg(t_tab *tpf, int argsize);
void			ft_precision_pos(t_tab *tpf, int val, int argsize);
void			ft_precision_ui(t_tab *tpf, int val, int argsize);
int				ft_wildcard(t_tab *tpf, int i);

#endif
