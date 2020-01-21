/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_annex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:34:16 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/13 20:42:38 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	*ft_putnbr(int nb)
{
	if (g_ptr_union->entier == 0 && g_ptr_elem->precision == 1
	&& g_ptr_elem->precision_value == 0
	&& g_ptr_elem->save_precision_value != 1)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (NULL);
}

void	*ft_putnbr_unsigned(unsigned int nb)
{
	if (g_ptr_union->u_entier == 0 && g_ptr_elem->precision == 1
	&& g_ptr_elem->precision_value == 0
	&& g_ptr_elem->save_precision_value != 1)
		return (NULL);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_cmp_global++;
}

void	ft_write_precision(void)
{
	int	cmp;

	cmp = 0;
	while (g_ptr_elem->precision_value > cmp)
	{
		ft_putchar('0');
		cmp++;
	}
}

void	ft_write_options(void)
{
	if (g_ptr_elem->width_value > 0 && g_ptr_elem->align_left == 0
		&& g_ptr_elem->width_zero == 0)
		ft_write_width();
	if (((g_ptr_elem->type == 'd' || g_ptr_elem->type == 'i')
		&& g_ptr_union->entier < 0) || g_ptr_elem->negative == 1)
		ft_putchar('-');
}
