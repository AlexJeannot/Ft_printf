/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajust_arg_int_min.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:47:11 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/11 18:07:09 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_ajust_int_min(void)
{
	if (g_ptr_elem->precision == 1 && g_ptr_elem->precision_value > 0)
	{
		g_ptr_elem->precision_value -= ft_count_unsigned(g_ptr_union->u_entier);
		if (g_ptr_elem->precision_value >= 0)
			g_ptr_elem->width_value -= (ft_count_unsigned(g_ptr_union->u_entier)
			+ g_ptr_elem->precision_value + 1);
		else
			g_ptr_elem->width_value -=
			(ft_count_unsigned(g_ptr_union->u_entier) + 1);
	}
	else if (g_ptr_elem->width_value > 0)
		g_ptr_elem->width_value -=
		(ft_count_unsigned(g_ptr_union->u_entier) + 1);
}
