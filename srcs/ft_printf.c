/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:28:02 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/09 20:30:51 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_exec_cond(int cmp, int ret_set, const char *format, va_list ap)
{
	cmp = ret_set;
	if (ft_exec_fct(ap, format[cmp]) == -1)
		return (-1);
	cmp++;
	return (cmp);
}

int	ft_exec_fct(va_list ap, char c)
{
	if (g_ptr_elem->percentage == 1)
		ft_putchar(c);
	else
	{
		if (!(ft_create_union()))
			return (-1);
		if (ft_add_arg(ap, c) == 0)
			return (-1);
		ft_ajust_undefined();
		ft_ajust_dispatch();
		ft_write_dispatch();
	}
	ft_clear_elem();
	return (1);
}

int	ft_exec_else(int cmp, char c)
{
	ft_putchar(c);
	cmp++;
	return (cmp);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cmp;
	int		ret_set;

	va_start(ap, format);
	cmp = 0;
	g_cmp_global = 0;
	while (format[cmp])
	{
		if (format[cmp] == '%' && (format[cmp + 1] != '\0'))
		{
			if ((ret_set = ft_set_struct(&format[cmp + 1], cmp, ap)) == -2)
				return (-1);
			if (ret_set != cmp)
			{
				if ((cmp = ft_exec_cond(cmp, ret_set, format, ap)) == -1)
					return (-1);
			}
			else
				cmp = ft_exec_else(cmp, format[cmp]);
		}
		else
			cmp = ft_exec_else(cmp, format[cmp]);
	}
	return (g_cmp_global);
}
