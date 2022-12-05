/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:58:09 by asaouab           #+#    #+#             */
/*   Updated: 2022/12/03 12:08:36 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkformat(va_list arg, char ch)
{
	int	len;

	len = 0;
	if (ch == '%')
		len += ft_putchar ('%');
	else if (ch == 'c')
		len += ft_putchar (va_arg(arg, int));
	else if (ch == 's')
		len += ft_putstr (va_arg(arg, char *));
	else if (ch == 'i' || ch == 'd')
	len += ft_putnbr (va_arg(arg, int));
	else if (ch == 'X' || ch == 'x')
		len += ft_puthex (va_arg(arg, unsigned int), ch);
	else if (ch == 'p')
	{
		len += ft_putstr ("0x");
		len += ft_puthex (va_arg(arg, unsigned long), ch);
	}
	else if (ch == 'u')
	len += ft_putnbr_un (va_arg(arg, unsigned int));
	else
	len += ft_putchar (ch);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start (list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == '\0')
				break ;
			len += checkformat (list, format[i]);
			i++;
		}
		else
		{
			len += ft_putchar (format[i]);
			i++;
		}
	}
	return (len);
}
