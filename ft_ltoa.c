/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:16:30 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 10:21:10 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltoa(long n)
{
	int		len;
	long	no;
	char	*pr;

	no = n;
	len = ft_longlen(n);
	if (n < 0)
		len++;
	pr = (char *)ft_calloc(len + 1, 1);
	if (!pr)
		return (0);
	while (len > 0)
	{	
		if (n < 0)
			pr[len - 1] = -(n % 10) + 48;
		else
			pr[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (no < 0)
		*pr = '-';
	return (pr);
}
