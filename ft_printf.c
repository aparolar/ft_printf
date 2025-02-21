/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:56:06 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 11:07:55 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/*
**  %[flags][width][.precision]type
*/

void	ft_reset_t_printf(t_printf *tc)
{
	tc->width = 0;
	tc->type = 0;
	tc->itsok = 0;
}

int	ft_printf(const char *s, ...)
{
	t_printf	tc;
	char		*str;

	if (!s || !*s)
		return (0);
	(&tc)->str = (char *)s;
	va_start((&tc)->args, s);
	(&tc)->len = 0;
	while (*(&tc)->str)
	{
		str = (&tc)->str;
		ft_reset_t_printf(&tc);
		ft_preparse(&tc);
		if (!(&tc)->itsok)
		{
			(&tc)->str = str;
			(&tc)->len += ft_putchar(*(&tc)->str);
			(&tc)->str++;
		}
	}
	va_end((&tc)->args);
	return ((&tc)->len);
}
