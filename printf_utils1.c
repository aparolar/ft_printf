/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:57:07 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/27 19:31:00 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_ullen(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*hex_ultoa(unsigned long n, int isupper)
{
	int		len;
	char	*ret;

	len = hex_ullen(n);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	ret[len] = 0;
	while (len-- > 0)
	{
		ret[len] = HEX[(n % 16)];
		if (isupper && ret[len] >= 'a' && ret[len] <= 'f')
			ret[len] -= 32;
		n /= 16;
	}
	return (ret);
}
