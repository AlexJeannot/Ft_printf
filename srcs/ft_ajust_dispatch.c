/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajust_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:13:47 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/13 20:42:11 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_ajust_dispatch(void)
{
	if (g_ptr_elem->type == 's')
		ft_ajust_str();
	else if (g_ptr_elem->type == 'p')
		ft_ajust_ptr();
	else if (g_ptr_elem->type == 'c')
		ft_ajust_char();
	else if ((g_ptr_elem->type == 'd' || g_ptr_elem->type == 'i')
			&& g_ptr_elem->negative == 0)
		ft_ajust_int();
	else if ((g_ptr_elem->type == 'd' || g_ptr_elem->type == 'i')
			&& g_ptr_elem->negative == 1)
		ft_ajust_int_min();
	else if (g_ptr_elem->type == 'u')
		ft_ajust_unsigned_int();
	else if (g_ptr_elem->type == 'x' || g_ptr_elem->type == 'X')
		ft_ajust_hexa();
	else if (g_ptr_elem->type == '%')
		ft_ajust_percent();
	if (g_ptr_elem->precision_value < 0)
		g_ptr_elem->precision_value = 0;
	if (g_ptr_elem->width_value < 0)
		g_ptr_elem->width_value = 0;
}

void	ft_ajust_undefined(void)
{
	if (g_ptr_elem->type == 'd' || g_ptr_elem->type == 'i'
	|| g_ptr_elem->type == 'x' || g_ptr_elem->type == 'X'
	|| g_ptr_elem->type == 'u')
	{
		if (g_ptr_elem->width_zero == 1 && g_ptr_elem->align_left == 1)
			g_ptr_elem->width_zero = 0;
		if (g_ptr_elem->width_zero == 1 && g_ptr_elem->precision == 1)
			g_ptr_elem->width_zero = 0;
	}
	else if (g_ptr_elem->type == 'c' || g_ptr_elem->type == 's'
	|| g_ptr_elem->type == 'p')
	{
		if (g_ptr_elem->type == 'c')
			if (g_ptr_elem->precision == 1)
				g_ptr_elem->precision = 0;
	}
	else if (g_ptr_elem->type == '%')
	{
		if (g_ptr_elem->width_zero == 1 && g_ptr_elem->align_left == 1)
			g_ptr_elem->width_zero = 0;
		if (g_ptr_elem->precision == 1)
			g_ptr_elem->precision = 0;
	}
}

void	ft_ajust_percent(void)
{
	if (g_ptr_elem->width_value > 0)
	{
		g_ptr_elem->width_value--;
	}
}

void	ft_ajust_hexa(void)
{
	if (g_ptr_elem->precision == 1 && g_ptr_elem->precision_value > 0)
	{
		g_ptr_elem->precision_value -= ft_strlen(g_ptr_union->str);
		if (g_ptr_elem->precision_value >= 0)
			g_ptr_elem->width_value -= (ft_strlen(g_ptr_union->str)
			+ g_ptr_elem->precision_value);
		else
			g_ptr_elem->width_value -= (ft_strlen(g_ptr_union->str));
	}
	else if (g_ptr_elem->width_value > 0)
	{
		g_ptr_elem->width_value -= ft_strlen(g_ptr_union->str);
		if (g_ptr_union->str[0] == '0' && ft_strlen(g_ptr_union->str) == 1
		&& g_ptr_elem->precision == 1 && g_ptr_elem->precision_value == 0)
			g_ptr_elem->width_value++;
	}
}
