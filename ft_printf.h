/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:57:53 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/24 13:08:04 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
**  Defines
*/

# define TYPES "cspdiuxX%"
# define HEX "0123456789abcdef"

/*
**  Structures;
*/

typedef struct s_printf
{
	char	*str;
	va_list	args;
	int		width;
	int		len;
	char	type;
	int		itsok;
}			t_printf;

/*
**  Functions
*/

int		ft_printf(const char *s, ...);
void	ft_reset_t_printf(t_printf *tc);
int		ft_padding(int width, char c);
int		ft_preparse(t_printf *tc);
int		hex_ullen(unsigned long n);
char	*hex_ultoa(unsigned long n, int isupper);
void	ft_parse_c(t_printf *tc);
void	ft_parse_s(t_printf *tc);
void	ft_parse_p(t_printf *tc);
void	ft_parse_diu(t_printf *tc);
void	ft_parse_x(t_printf	*tc);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_longlen(long n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_ltoa(long n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);

#endif
