/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:21:32 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/10 18:21:31 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	*ft_create_elem(void)
{
	t_elem	*new_elem;

	if (!(new_elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	new_elem->align_left = 0;
	new_elem->percentage = 0;
	new_elem->width_zero = 0;
	new_elem->width_value = 0;
	new_elem->precision = 0;
	new_elem->precision_value = 0;
	new_elem->negative = 0;
	new_elem->type = 0;
	g_ptr_elem = new_elem;
	return (new_elem);
}

void	*ft_create_union(void)
{
	t_value	*new_elem;

	if (!(new_elem = (t_value *)malloc(sizeof(t_value))))
		return (NULL);
	new_elem->entier = 0;
	new_elem->u_entier = 0;
	new_elem->c = 0;
	new_elem->str = NULL;
	g_ptr_union = new_elem;
	return (new_elem);
}

void	ft_clear_elem(void)
{
	if (g_ptr_elem->type == 'p' || g_ptr_elem->type == 'x'
	|| g_ptr_elem->type == 'X')
	{
		free(g_ptr_union->str);
		g_ptr_union->str = NULL;
	}
	if (g_ptr_elem)
	{
		free(g_ptr_elem);
		g_ptr_elem = NULL;
	}
	if (g_ptr_union)
	{
		free(g_ptr_union);
		g_ptr_union = NULL;
	}
}
