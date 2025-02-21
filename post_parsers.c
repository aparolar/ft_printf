/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:56:49 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 13:08:58 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_parse_c(t_printf *tc)
{
	int	c;

	c = va_arg(tc->args, int);
	tc->len += ft_padding(tc->width - 1, ' ');
	ft_putchar(c);
	tc->len++;
}

void	ft_parse_diu(t_printf *tc)
{
	char	*pstr;
	long	value;

	if (tc->type == 'u')
		value = va_arg(tc->args, unsigned int);
	else
		value = va_arg(tc->args, int);
	pstr = ft_ltoa(value);
	tc->len += ft_padding(tc->width - ft_strlen(pstr), ' ');
	tc->len += ft_putstr(pstr);
	free(pstr);
}

void	ft_parse_p(t_printf *tc)
{
	unsigned long	value;
	char			*ptr;

	value = (unsigned long)va_arg(tc->args, unsigned long);
	ptr = hex_ultoa(value, 0);
	if (ptr)
	{
		tc->len += ft_padding(tc->width - ft_strlen(ptr) - 2, ' ');
		tc->len += ft_putstr("0x");
		tc->len += ft_putstr(ptr);
		free(ptr);
	}
}

void	ft_parse_s(t_printf *tc)
{
	char	*s;

	s = va_arg(tc->args, char *);
	if (!s)
		s = "(null)";
	tc->len += ft_padding(tc->width - ft_strlen(s), ' ');
	tc->len += ft_putstr(s);
}

void	ft_parse_x(t_printf *tc)
{
	int unsigned	value;
	char			*ptr;

	value = va_arg(tc->args, int);
	if (tc->type == 'X')
		ptr = hex_ultoa(value, 1);
	else
		ptr = hex_ultoa(value, 0);
	if (ptr)
	{
		tc->len += ft_padding(tc->width - ft_strlen(ptr), ' ');
		tc->len += ft_putstr(ptr);
		free(ptr);
	}
}
