/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreijo- <sfreijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:36:05 by sfreijo-          #+#    #+#             */
/*   Updated: 2022/09/28 20:24:07 by sfreijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		num;

	num = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			num += ft_arg_printf(args, *++str);
		}
		else
			num += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (num);
}

int	ft_arg_printf(va_list args, char chr)
{
	int	cont;

	cont = 0;
	if (chr == '%')
		cont += ft_putchar('%');
	else if (chr == 'c')
		cont += ft_putchar(va_arg (args, int));
	else if (chr == 's')
			cont += ft_putstr(va_arg (args, char *));
	else if (chr == 'p')
	{
		cont += ft_putstr("0x") + ft_hexa(va_arg(args, unsigned long int), chr);
	}
	else if (chr == 'd')
			cont += ft_putnbr_total(va_arg (args, int));
	else if (chr == 'i')
			cont += ft_putnbr_total(va_arg (args, int));
	else if (chr == 'u')
			cont += ft_putnum(va_arg (args, unsigned int));
	else if (chr == 'x' || chr == 'X')
			cont += ft_hexa(va_arg (args, unsigned int), chr);
	return (cont);
}
