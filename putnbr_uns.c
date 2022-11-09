/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 06:46:41 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/08 16:05:31 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int n)
{
	unsigned int	x;

	x = 0;
	if (n > 9)
	{
		x += ft_putnbr(n / 10);
		x += ft_putchar((n % 10) + 48);
	}
	else
		x += ft_putchar(n + 48);
	return (x);
}
