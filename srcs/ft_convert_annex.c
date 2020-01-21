/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_annex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:56:11 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/12 20:16:47 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_add_prefix(char *str, int cmp)
{
	str[0] = '0';
	str[1] = 'x';
	str[cmp + 1] = '\0';
	return (str);
}

int		ft_count_convert(unsigned long int nb)
{
	int cmp;

	cmp = 0;
	while (nb >= 16)
	{
		nb = nb / 16;
		cmp++;
	}
	return (cmp);
}

void	ft_write_ptr_null_precision(void)
{
	int	cmp;

	cmp = 0;
	while (g_ptr_union->str[cmp])
	{
		ft_putchar(g_ptr_union->str[cmp]);
		cmp++;
	}
}

void	ft_free(void)
{
	free(g_ptr_elem);
	g_ptr_elem = NULL;
}
