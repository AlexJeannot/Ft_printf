/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:53:22 by ajeannot          #+#    #+#             */
/*   Updated: 2019/12/16 13:52:02 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <assert.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef union	u_value
{
	long int			entier;
	unsigned int		u_entier;
	unsigned long int	u_long;
	char				c;
	char				*str;
}				t_value;

typedef struct	s_elem
{
	int		align_left;
	int		percentage;
	int		width_zero;
	int		width_value;
	int		precision;
	int		precision_value;
	int		save_precision_value;
	int		negative;
	char	type;
}				t_elem;

t_elem			*g_ptr_elem;
t_value			*g_ptr_union;
int				g_cmp_global;

int				ft_exec_cond(int cmp, int ret_set,
				const char *format, va_list ap);
int				ft_exec_fct(va_list ap, char c);
int				ft_exec_else(int cmp, char c);
int				ft_printf(const char *format, ...);
void			ft_free(void);
int				ft_add_arg(va_list ap, char c);
char			*ft_add_str(char *str);
void			ft_add_int(int nb);
void			*ft_create_elem(void);
void			*ft_create_union(void);
void			ft_clear_elem(void);
int				ft_set_struct(const char *str, int input_cmp, va_list ap);
int				ft_set_percent(int cmp);
int				ft_set_width_type(const char *str);
int				ft_set_width_value(const char *str, int cmp, va_list ap);
int				ft_set_precision(const char *str, int cmp, va_list ap);
int				ft_set_type(char c, int cmp, int input_cmp);
char			*ft_convert_hexa(unsigned int nb);
char			*ft_convert_ptr(unsigned long int nb);
char			*ft_ajust_convert(char *str);
char			ft_sort_convert(unsigned long int nb);
char			*ft_convert_ptr_null_precision();
int				ft_count_convert(unsigned long int nb);
char			*ft_add_prefix(char *str, int cmp);
void			ft_ajust_undefined(void);
void			ft_ajust_dispatch(void);
void			ft_ajust_str(void);
void			ft_ajust_char(void);
void			ft_ajust_ptr(void);
void			ft_ajust_int(void);
void			ft_ajust_int_min(void);
void			ft_ajust_unsigned_int(void);
void			ft_ajust_hexa(void);
void			ft_ajust_percent(void);
void			ft_write_dispatch(void);
void			ft_write_options(void);
void			ft_write_width_zero(void);
void			ft_write_width(void);
void			ft_write_precision(void);
void			*ft_write_str(void);
void			*ft_write_hexa(void);
void			ft_write_ptr_null_precision(void);
void			ft_putchar(char c);
void			*ft_putnbr(int nb);
void			*ft_putnbr_unsigned(unsigned int nb);
int				ft_count(int nb);
int				ft_count_unsigned(unsigned int nb);
int				ft_search(char c);
int				ft_atoi_diff(const char *nptr);
int				ft_strlen(char *str);

#endif
