/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_hx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 06:46:30 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/08 17:21:00 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_p(unsigned long nb)
{
	unsigned long	j;

	j = 0;
	if (nb >= 16)
	{
		j += ft_hexa_p(nb / 16);
		j += ft_hexa_p(nb % 16);
	}
	else if (nb > 9)
	{
		j += ft_putchar(nb + 87);
	}
	else
		j += ft_putchar((nb + 48));
	return (j);
}

int	ft_pointer_hx(unsigned long nb)
{
	unsigned long	x;

	x = 2;
	ft_putstr("0x");
	x += ft_hexa_p(nb);
	return (x);
}
