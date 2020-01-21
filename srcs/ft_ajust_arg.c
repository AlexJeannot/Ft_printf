/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajust_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:12:17 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/13 20:41:31 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_ajust_str(void)
{
	if (g_ptr_elem->precision == 1 && g_ptr_elem->precision_value >= 0)
	{
		if (g_ptr_elem->precision_value < g_ptr_elem->width_value &&
				ft_strlen(g_ptr_union->str) > g_ptr_elem->precision_value)
			g_ptr_elem->width_value -= g_ptr_elem->precision_value;
		else
			g_ptr_elem->width_value -= ft_strlen(g_ptr_union->str);
	}
	else if (g_ptr_elem->width_value > 0)
		g_ptr_elem->width_value -= ft_strlen(g_ptr_union->str);
}

void	ft_ajust_ptr(void)
{
	if (g_ptr_elem->precision == 1 && g_ptr_elem->precision_value >= 0
	&& ft_strlen(g_ptr_union->str) == 2)
		g_ptr_elem->width_value -= 2;
	else if (g_ptr_elem->width_value > 0)
		g_ptr_elem->width_value -= ft_strlen(g_ptr_union->str);
}

void	ft_ajust_char(void)
{
	if (g_ptr_elem->width_value > 0)
		g_ptr_elem->width_value--;
}

void	ft_ajust_int(void)
{
	int i;

	if (g_ptr_union->entier < 0)
		i = 1;
	else
		i = 0;
	if (g_ptr_elem->precision == 1 && g_ptr_elem->precision_value > 0)
	{
		g_ptr_elem->precision_value -= ft_count(g_ptr_union->entier);
		if (g_ptr_elem->precision_value >= 0)
			g_ptr_elem->width_value -= (ft_count(g_ptr_union->entier)
			+ g_ptr_elem->precision_value + i);
		else
			g_ptr_elem->width_value -= (ft_count(g_ptr_union->entier) + i);
	}
	else if (g_ptr_elem->width_value > 0)
	{
		g_ptr_elem->width_value -= (ft_count(g_ptr_union->entier) + i);
		if (g_ptr_union->entier == 0 && g_ptr_elem->precision == 1
		&& g_ptr_elem->precision_value == 0)
			g_ptr_elem->width_value++;
	}
}

void	ft_ajust_unsigned_int(void)
{
	if (g_ptr_elem->precision == 1 && g_ptr_elem->precision_value > 0)
	{
		g_ptr_elem->precision_value -=
			ft_count_unsigned(g_ptr_union->u_entier);
		if (g_ptr_elem->precision_value >= 0)
			g_ptr_elem->width_value -=
				(ft_count_unsigned(g_ptr_union->u_entier)
			+ g_ptr_elem->precision_value);
		else
			g_ptr_elem->width_value -=
			(ft_count_unsigned(g_ptr_union->u_entier));
	}
	else if (g_ptr_elem->width_value > 0)
	{
		g_ptr_elem->width_value -= ft_count_unsigned(g_ptr_union->u_entier);
		if (g_ptr_union->u_entier == 0 && g_ptr_elem->precision == 1
		&& g_ptr_elem->precision_value == 0)
			g_ptr_elem->width_value++;
	}
}
