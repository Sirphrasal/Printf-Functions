/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreijo- <sfreijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:04:39 by sfreijo-          #+#    #+#             */
/*   Updated: 2022/09/28 20:47:19 by sfreijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	cont;

	cont = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		cont += ft_putchar(*str);
		str++;
	}
	return (cont);
}

int	ft_putnum(unsigned int num)
{
	int	cont;

	cont = 0;
	if (num >= 10)
		cont = ft_putnum(num / 10);
	num = num % 10;
	if (num < 10)
		cont += ft_putchar(num + '0');
	return (cont);
}

int	ft_hexa(unsigned long int numb, char chr)
{
	int	res;

	res = 0;
	if (chr == 'x' || chr == 'p')
	{
		if (numb >= 16)
			res = ft_hexa(numb / 16, chr);
		res += ft_putchar("0123456789abcdef"[numb % 16]);
	}
	else if (chr == 'X')
	{
		if (numb >= 16)
			res = ft_hexa(numb / 16, chr);
		res += ft_putchar("0123456789ABCDEF"[numb % 16]);
	}
	return (res);
}

int	ft_putnbr_total(int nb)
{
	int	tot;

	tot = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		tot += write (1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		tot += ft_putnum(nb / 10);
	nb = nb % 10;
	if (nb < 10)
		tot += ft_putchar (nb + '0');
	return (tot);
}
