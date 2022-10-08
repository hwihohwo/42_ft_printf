/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:12:23 by seonghwc          #+#    #+#             */
/*   Updated: 2022/09/29 23:21:36 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_info
{
	int	c_flag;
	int	s_flag;
	int	p_flag;
	int	d_flag;
	int	i_flag;
	int	u_flag;
	int	x_flag;
	int	low_x_flag;
	int	percent_flag;
	int	width;
	int	minus_flag;
	int	zero_flag;
	int	dot_flag;
	int	precision;
	int	sharp_flag;
	int	space_flag;
	int	plus_flag;
}	t_info;

char	*g_specifier;

g_specifier = "cspdiuxX%";

t_list	*make_buffer(const char *str);
int		count_string_length(char *str, int j);
char	*make_tmp(int count, char *str);
int		is_specifier(char c, char *specifier);
void	check_info(t_list *buffer, t_info *info);
void	input_info(char *str, t_info *info);
void	check_specifier(char c, t_info *info);
void	initializing_info(t_info *info);
void	input_flags(char c, t_info *info);
int		check_flags(char c);
#endif