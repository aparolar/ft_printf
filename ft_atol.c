/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:10:39 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 10:20:36 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_atol(const char *str)
{
	int			sign;
	long		num;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		if (num * sign > LONG_MAX)
			return (-1);
		else if (num * sign < LONG_MIN)
			return (0);
		num = (num * 10) + *str - 48;
		str++;
	}
	num *= sign;
	return (num);
}
