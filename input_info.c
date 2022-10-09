/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:14:30 by seonghwc          #+#    #+#             */
/*   Updated: 2022/09/30 00:43:56 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int		check_flags(char c)
{
	int	ret;

	ret = 0;
	if (c == '0')
		ret = 1;
	else if (c == '-')
		ret = 1;
	else if (c == ' ')
		ret = 1;
	else if (c == '+')
		ret = 1;
	else if (c == '#')
		ret = 1;
	return (ret);
}

void	input_flags(char c, t_info *info)
{
	if (info->minus_flag != 1 && c == '0')
		info->zero_flag = 1;
	else if (c == '-')
	{
		info->minus_flag = 1;
		info->zero_flag = 0;
	}
	else if (info->plus_flag != 1 && c == ' ')
		info->space_flag = 1;
	else if (c == '+')
	{
		info->plus_flag = 1;
		info->space_flag = 0;
	}
	else if (c == '#')
		info->sharp_flag = 1;
}

void	initializing_info(t_info *info)
{
	info->s_flag = 0;
	info->c_flag = 0;
	info->p_flag = 0;
	info->d_flag = 0;
	info->i_flag = 0;
	info->u_flag = 0;
	info->x_flag = 0;
	info->low_x_flag = 0;
	info->percent_flag = 0;
	info->width = 0;
	info->minus_flag = 0;
	info->zero_flag = 0;
	info->dot_flag = 0;
	info->sharp_flag = 0;
	info->space_flag = 0;
	info->plus_flag = 0;
}

void	check_specifier(char c, t_info *info)
{
	if (c == 'c')
		info->c_flag = 1;
	else if (c == 's')
		info->s_flag = 1;
	else if (c == 'p')
		info->p_flag = 1;
	else if (c == 'd')
		info->d_flag = 1;
	else if (c == 'i')
		info->i_flag = 1;
	else if (c == 'u')
		info->u_flag = 1;
	else if (c == 'X')
		info->x_flag = 1;
	else if (c == 'x')
		info->low_x_flag = 1;
	else if (c == '%')
		info->percent_flag = 1;
}

void	input_info(char *str, t_info *info)
{
	int	i;

	i = 1;
	initializing_info(info);
	while (check_flags(str[i]))
		input_flags(str[i++], info);
	if (str[i] >= '1' && str[i] <= '9')
		info->width = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		info->dot_flag = 1;
		info->zero_flag = 0;
		i++;
		info->precision = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
		i++;
	}
	check_specifier(str[i], info);
}