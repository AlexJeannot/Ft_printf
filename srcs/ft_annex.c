/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:15:59 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/09 20:17:47 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_count(int nb)
{
	int	cmp;

	cmp = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > 9)
	{
		nb = nb / 10;
		cmp++;
	}
	return (cmp);
}

int	ft_count_unsigned(unsigned int nb)
{
	unsigned int	cmp;

	cmp = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > 9)
	{
		nb = nb / 10;
		cmp++;
	}
	return (cmp);
}

int	ft_search(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'x'
	|| c == 'X' || c == 'u' || c == 'p' || c == '%')
		return (1);
	else
		return (-1);
}

int	ft_atoi_diff(const char *nptr)
{
	int	i;
	int	nb_final;

	i = 0;
	nb_final = 0;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nb_final = (nb_final * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb_final);
}
