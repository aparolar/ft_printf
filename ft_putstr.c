/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 05:28:44 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 10:45:00 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	char	*pstr;
	int		len;

	len = 0;
	pstr = (char *)str;
	if (pstr)
	{
		while (*pstr)
		{
			if (write(1, pstr, 1))
				len++;
			pstr++;
		}
	}
	return (len);
}
