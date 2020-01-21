/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:18:07 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/17 14:26:53 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_convert_hexa(unsigned int nb)
{
	int					cmp;
	unsigned long int	nb_cpy;
	char				*str;

	nb_cpy = nb;
	cmp = 0;
	while (nb_cpy >= 16)
	{
		nb_cpy = nb_cpy / 16;
		cmp++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (cmp + 2))))
		return (NULL);
	str[cmp + 1] = '\0';
	while (nb >= 16)
	{
		str[cmp] = ft_sort_convert(nb);
		nb = nb / 16;
		cmp--;
	}
	str[cmp] = ft_sort_convert(nb);
	if (g_ptr_elem->type == 'X')
		str = ft_ajust_convert(str);
	return (str);
}

char	*ft_convert_ptr(unsigned long int nb)
{
	int					cmp;
	unsigned long int	nb_cpy;
	char				*str;

	if (nb == 0 && g_ptr_elem->precision == 1
	&& g_ptr_elem->precision_value == 0)
		return (ft_convert_ptr_null_precision());
	nb_cpy = nb;
	cmp = ft_count_convert(nb_cpy);
	cmp += 2;
	if (!(str = (char *)malloc(sizeof(char) * (cmp + 2))))
		return (NULL);
	str = ft_add_prefix(str, cmp);
	while (nb >= 16)
	{
		str[cmp] = ft_sort_convert(nb);
		nb = nb / 16;
		cmp--;
	}
	str[cmp] = ft_sort_convert(nb);
	return (str);
}

char	*ft_ajust_convert(char *str)
{
	int	cmp;

	cmp = 0;
	while (str[cmp])
	{
		if (str[cmp] > 96 && str[cmp] < 103)
			str[cmp] = str[cmp] - 32;
		cmp++;
	}
	return (str);
}

char	ft_sort_convert(unsigned long int nb)
{
	if (nb % 16 <= 9)
		return ((nb % 16) + 48);
	else
		return ((nb % 16) + 87);
}

char	*ft_convert_ptr_null_precision(void)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '\0';
	return (str);
}
