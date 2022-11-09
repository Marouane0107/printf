/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 03:59:07 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/09 11:52:57 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *p, va_list arg, int i, int size)
{
	while (p[i])
	{
		if (p[i] == '%' && p[i + 1])
		{
			if (p[i + 1] == 'c')
				size += ft_putchar(va_arg(arg, unsigned int));
			else if (p[i + 1] == 's')
				size += ft_putstr(va_arg(arg, char *));
			else if (p[i + 1] == 'p')
				size += ft_pointer_hx(va_arg(arg, unsigned long));
			else if (p[i + 1] == 'd' || p[i + 1] == 'i')
				size += ft_putnbr(va_arg(arg, int));
			else if (p[i + 1] == 'u')
				size += ft_putnbr_uns(va_arg(arg, unsigned int));
			else if (p[i + 1] == 'X' || p[i + 1] == 'x')
				size += ft_hexa(va_arg(arg, unsigned int), p[i + 1]);
			else
				size += ft_putchar(p[i + 1]);
			i++;
		}
		else if (p[i] != '%')
			size += ft_putchar(p[i]);
		i++;
	}
	return (size);
}

int	ft_printf(const char *p, ...)
{
	int		x;
	va_list	prt;

	va_start(prt, p);
	x = ft_type(p, prt, 0, 0);
	va_end(prt);
	return (x);
}
