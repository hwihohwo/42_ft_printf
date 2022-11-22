/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:11:18 by marvin            #+#    #+#             */
/*   Updated: 2022/11/21 20:49:41 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_result(va_list *ap, t_info *info)
{
	char	*ret;

	ret = (char *)malloc(2);
	if (ret == 0)
		return (0);
	ret[0] = va_arg(*ap, int);
	if (ret[0] == '\0')
	{
		info->length++;
		info->c_null_flag = 1;
	}
	ret[1] = '\0';
	return (ret);
}

char	*s_result(va_list *ap, t_info *info)
{
	int		i;
	char	*str_temp;
	char	*ret;

	i = 0;
	str_temp = va_arg(*ap, char *);
	if (str_temp == 0)
		str_temp = "(null)";
	if (info->dot_flag == 1)
		ret = (char *)malloc(info->precision + 1);
	else
		ret = (char *)malloc(ft_strlen(str_temp) + 1);
	if (ret == 0)
		return (0);
	while (str_temp[i])
	{
		if (info->dot_flag == 1)
			if (i >= info->precision)
				break ;
		ret[i] = str_temp[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*p_result(va_list *ap)
{
	int				length;
	unsigned long	addr;
	char			*base_list;
	char			*ret;

	addr = va_arg(*ap, unsigned long);
	base_list = "0123456789abcdef";
	length = calc_length(16, addr);
	length += 2;
	ret = (char *)malloc(length + 1);
	if (ret == 0)
		return (0);
	ret[length] = 0;
	ret[0] = '0';
	ret[1] = 'x';
	while (--length > 1)
	{
		ret[length] = base_list[addr % 16];
		addr /= 16;
	}
	return (ret);
}

char	*d_result(t_info *info, va_list *ap)
{
	long	num;
	int		length;
	char	*ret1;
	char	*ret2;
	char	*ret;

	length = 0;
	num = va_arg(*ap, int);
	if (num < 0 || info->plus_flag || info->space_flag)
		length++;
	if (info->dot_flag == 1 && info->precision == 0 && num == 0)
		info->d_zero_flag = 1;
	ret1 = (char *)malloc(length + 1);
	if (ret1 == NULL)
		return (NULL);
	ret1[length] = 0;
	put_d_front(num, ret1, info);
	if (num < 0)
		num *= -1;
	ret2 = write_num(10, num, info->precision);
	ret = ft_strjoin(ret1, ret2);
	free_all(ret1, ret2);
	return (ret);
}

char	*u_result(t_info *info, va_list *ap)
{
	long	num;
	int		length;
	char	*ret1;
	char	*ret2;
	char	*ret;

	length = 0;
	num = va_arg(*ap, unsigned int);
	if (num < 0 || info->plus_flag || info->space_flag)
		length++;
	if (info->dot_flag == 1 && info->precision == 0 && num == 0)
		info->d_zero_flag = 1;
	ret1 = (char *)malloc(length + 1);
	if (ret1 == 0)
		return (0);
	ret1[length] = 0;
	if (num >= 0 && info->space_flag)
		ret1[0] = ' ';
	else if (num >= 0 && info->plus_flag)
		ret1[0] = '+';
	ret2 = write_num(10, num, info->precision);
	ret = ft_strjoin(ret1, ret2);
	free_all(ret1, ret2);
	return (ret);
}
