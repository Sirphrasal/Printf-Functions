/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreijo- <sfreijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:14:45 by sfreijo-          #+#    #+#             */
/*   Updated: 2022/09/28 20:23:49 by sfreijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_putchar(char c);
int			ft_printf(char const *str, ...);
int			ft_putnum(unsigned int num);
int			ft_putstr(char *str);
int			ft_hexa(unsigned long int numb, char chr);
int			ft_putnbr_total(int nb);
int			ft_arg_printf(va_list args, char chr);
#endif