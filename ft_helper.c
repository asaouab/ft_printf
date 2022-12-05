/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:04:08 by asaouab           #+#    #+#             */
/*   Updated: 2022/12/01 12:38:08 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	size_t	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	size_t	len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	len += ft_putchar((nb % 10) + 48);
	return (len);
}

int	ft_putnbr_un(unsigned int n)
{
	size_t	len;
	long	nb;

	len = 0;
	nb = n;
	if (nb >= 10)
	{
		len += ft_putnbr_un(nb / 10);
		len += ft_putchar ((nb % 10) + 48);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_puthex(unsigned long nb, char flag)
{
	char	*pt;
	size_t	len;

	if (flag == 'X')
		pt = "0123456789ABCDEF";
	else
		pt = "0123456789abcdef";
	len = 0;
	if (nb >= 16)
		len += ft_puthex(nb / 16, flag);
	len += ft_putchar(pt[nb % 16]);
	return (len);
}
