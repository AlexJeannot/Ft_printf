/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:30:59 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/13 20:44:16 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_write_dispatch(void)
{
	ft_write_options();
	if (g_ptr_elem->width_zero == 1)
		ft_write_width_zero();
	if (g_ptr_elem->precision == 1 && g_ptr_elem->type != 's')
		ft_write_precision();
	if (g_ptr_elem->type == 's' || g_ptr_elem->type == 'p')
		ft_write_str();
	if (g_ptr_elem->type == 'x' || g_ptr_elem->type == 'X')
		ft_write_hexa();
	else if (g_ptr_elem->type == 'c')
		ft_putchar(g_ptr_union->c);
	else if ((g_ptr_elem->type == 'd' || g_ptr_elem->type == 'i')
			&& g_ptr_elem->negative == 0)
		ft_putnbr(g_ptr_union->entier);
	else if ((g_ptr_elem->type == 'd' || g_ptr_elem->type == 'i')
			&& g_ptr_elem->negative == 1)
		ft_putnbr_unsigned(g_ptr_union->u_entier);
	else if (g_ptr_elem->type == 'u')
		ft_putnbr_unsigned(g_ptr_union->u_entier);
	else if (g_ptr_elem->type == '%')
		ft_putchar('%');
	if (g_ptr_elem->align_left == 1)
		ft_write_width();
}

void	ft_write_width_zero(void)
{
	int	cmp;

	cmp = 0;
	while (g_ptr_elem->width_value > cmp)
	{
		ft_putchar('0');
		cmp++;
	}
}

void	ft_write_width(void)
{
	int	cmp;

	cmp = 0;
	if (g_ptr_elem->type == 0)
		g_ptr_elem->width_value--;
	while (g_ptr_elem->width_value > cmp)
	{
		ft_putchar(' ');
		cmp++;
	}
}

void	*ft_write_str(void)
{
	int	cmp;

	cmp = 0;
	if (g_ptr_union->str[0] == '0' && ft_strlen(g_ptr_union->str) == 1
	&& g_ptr_elem->precision == 1 && g_ptr_elem->precision_value == 0)
		return (NULL);
	if (g_ptr_elem->type == 'p' && ft_strlen(g_ptr_union->str) == 2)
		ft_write_ptr_null_precision();
	else if (g_ptr_elem->precision == 1 && g_ptr_elem->type == 's')
		while (g_ptr_elem->precision_value > 0 && g_ptr_union->str[cmp])
		{
			ft_putchar(g_ptr_union->str[cmp]);
			cmp++;
			g_ptr_elem->precision_value--;
		}
	else
		while (g_ptr_union->str[cmp])
		{
			ft_putchar(g_ptr_union->str[cmp]);
			cmp++;
		}
	return (NULL);
}

void	*ft_write_hexa(void)
{
	int	cmp;

	cmp = 0;
	if (g_ptr_union->str[0] == '0' && ft_strlen(g_ptr_union->str) == 1
	&& g_ptr_elem->precision == 1 && g_ptr_elem->precision_value == 0
	&& g_ptr_elem->save_precision_value != 1)
		return (NULL);
	while (g_ptr_union->str[cmp])
	{
		ft_putchar(g_ptr_union->str[cmp]);
		cmp++;
	}
	return (NULL);
}
