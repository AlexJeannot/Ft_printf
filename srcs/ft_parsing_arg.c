/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:23:41 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/12 20:04:07 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_set_width_type(const char *str)
{
	int cmp;

	cmp = 0;
	while (str[cmp] == '-' || str[cmp] == '0')
	{
		if (str[cmp] == '-')
		{
			while (str[cmp] == '-')
			{
				g_ptr_elem->align_left = 1;
				cmp++;
			}
		}
		if (str[cmp] == '0')
		{
			while (str[cmp] == '0')
			{
				g_ptr_elem->width_zero = 1;
				cmp++;
			}
		}
	}
	return (cmp);
}

int	ft_set_width_value(const char *str, int cmp, va_list ap)
{
	int cmp_zero;

	cmp_zero = 0;
	if (str[0] == '*')
	{
		g_ptr_elem->width_value = va_arg(ap, int);
		if (g_ptr_elem->width_value < 0)
		{
			g_ptr_elem->align_left = 1;
			g_ptr_elem->width_value *= -1;
		}
		cmp++;
	}
	else
	{
		while (str[cmp_zero] == '0' && (str[cmp_zero + 1]
		>= '0' && str[cmp_zero + 1] <= '9'))
			cmp_zero++;
		g_ptr_elem->width_value = ft_atoi_diff(str);
		cmp += ft_count(g_ptr_elem->width_value);
	}
	return (cmp + cmp_zero);
}

int	ft_set_precision(const char *str, int cmp, va_list ap)
{
	int cmp_zero;

	cmp_zero = 0;
	g_ptr_elem->precision = 1;
	cmp++;
	if (str[0] == '*')
	{
		g_ptr_elem->precision_value = va_arg(ap, int);
		if (g_ptr_elem->precision_value < 0)
			g_ptr_elem->precision = 0;
		cmp += 1;
	}
	else if (str[0] >= '0' && str[0] <= '9')
	{
		while (str[cmp_zero] == '0' && (str[cmp_zero + 1]
		>= '0' && str[cmp_zero + 1] <= '9'))
			cmp_zero++;
		g_ptr_elem->precision_value = ft_atoi_diff(str);
		cmp += ft_count(g_ptr_elem->precision_value);
	}
	g_ptr_elem->save_precision_value = g_ptr_elem->precision_value;
	return (cmp + cmp_zero);
}

int	ft_set_type(char c, int cmp, int input_cmp)
{
	g_ptr_elem->type = c;
	return (input_cmp + cmp + 1);
}

int	ft_set_struct(const char *str, int input_cmp, va_list ap)
{
	int	cmp;

	cmp = 0;
	if (!(ft_create_elem()))
		return (-2);
	if (ft_search(str[cmp]) != 1)
	{
		if (str[cmp] == '-' || str[cmp] == '0')
			cmp += ft_set_width_type(&str[cmp]);
		if (str[cmp] == '-' || str[cmp] == '0')
			cmp += ft_set_width_type(&str[cmp]);
		if (((str[cmp] >= '0' && str[cmp] <= '9') || str[cmp] == '*'))
			cmp = ft_set_width_value(&str[cmp], cmp, ap);
		if (str[cmp] == '.')
			cmp = ft_set_precision(&str[cmp + 1], cmp, ap);
		if (ft_search(str[cmp]) == 1)
			return (ft_set_type(str[cmp], cmp, input_cmp));
	}
	if (ft_search(str[cmp]) == 1)
		return (ft_set_type(str[cmp], cmp, input_cmp));
	if (cmp == 0)
		ft_free();
	return (input_cmp + cmp);
}
