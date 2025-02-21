/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:57:17 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 10:49:40 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padding(int width, char c)
{
	int	ret;

	ret = width;
	if (ret < 0)
		ret = 0;
	while (width-- > 0)
		ft_putchar(c);
	return (ret);
}
