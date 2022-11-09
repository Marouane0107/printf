/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:31:31 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/08 18:10:09 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long nb, int base)
{
	unsigned long	j;

	j = 0;
	if (nb >= 16)
	{
		j += ft_hexa(nb / 16, base);
		j += ft_hexa(nb % 16, base);
	}
	else if (nb > 9)
	{
		if (base == 'x')
			j += ft_putchar(nb + 87);
		else
			j += ft_putchar(nb + 55);
	}
	else
		j += ft_putchar((nb + 48));
	return (j);
}
