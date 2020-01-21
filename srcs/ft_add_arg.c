/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:01:18 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/13 20:40:05 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_add_arg(va_list ap, char c)
{
	if (c == 'c')
		g_ptr_union->c = va_arg(ap, int);
	else if (c == 's')
		g_ptr_union->str = ft_add_str(va_arg(ap, char *));
	else if (c == 'p')
	{
		if (!(g_ptr_union->str =
		ft_convert_ptr(va_arg(ap, unsigned long int))))
			return (0);
	}
	else if (c == 'd' || c == 'i')
		ft_add_int(va_arg(ap, int));
	else if (c == 'u')
		g_ptr_union->u_entier = va_arg(ap, unsigned int);
	else if (c == 'x' || c == 'X')
	{
		if (!(g_ptr_union->str = ft_convert_hexa(va_arg(ap, unsigned int))))
			return (0);
	}
	return (1);
}

char	*ft_add_str(char *str)
{
	if (str == NULL)
		return ("(null)");
	else
		return (str);
}

void	ft_add_int(int nb)
{
	if (nb == -2147483648)
	{
		g_ptr_elem->negative = 1;
		g_ptr_union->u_entier = 2147483648;
	}
	else
		g_ptr_union->entier = nb;
}
