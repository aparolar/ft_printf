/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:16:45 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 10:42:27 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  %[flags][width][.precision]type
**	flags
**		-	Rigth align blank-padding
**		0	Left align zero-padding overrides - flag
**	Width
**		padding size
**	dot
**		.	Precision only truncates str
**	precision
**		presicion size
**	type
**		cspdiuxX%	only one of dis set
*/

static int	ft_parsebypass(t_printf *tc)
{
	if (tc->type && --tc->itsok)
	{
		if (tc->type == 'c')
			ft_parse_c(tc);
		else if (tc->type == 's')
			ft_parse_s(tc);
		else if (tc->type == 'p')
			ft_parse_p(tc);
		else if (tc->type == 'd' || tc->type == 'i' || tc->type == 'u')
			ft_parse_diu(tc);
		else if (tc->type == 'x' || tc->type == 'X')
			ft_parse_x(tc);
		else if (tc->type == '%')
		{
			ft_putchar('%');
			tc->len++;
		}
	}
	return (tc->itsok);
}

static int	ft_getnumber(t_printf *tc)
{
	char	*str;
	int		value;

	str = tc->str;
	if (*str == '*')
	{
		str++;
		value = va_arg(tc->args, int);
	}
	else
	{
		while (*str && ft_isdigit(*str))
			str++;
		value = ft_atol(tc->str);
	}
	tc->str = str;
	return (value);
}

static char	ft_gettype(t_printf *tc)
{
	char	*str;

	str = TYPES;
	while (*tc->str && *str)
	{
		if (*tc->str == *str)
		{
			tc->str++;
			return (*str);
		}
		str++;
	}
	return (0);
}

int	ft_preparse(t_printf *tc)
{
	if (*tc->str == '%')
	{
		tc->str++;
		tc->width = ft_getnumber(tc);
		tc->type = ft_gettype(tc);
		return (ft_parsebypass(tc));
	}
	return (0);
}
