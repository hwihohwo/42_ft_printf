/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:11:18 by marvin            #+#    #+#             */
/*   Updated: 2022/10/12 19:54:59 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*c_result(t_info *info, va_list *ap)
{
	char	*ret;

	ret = (char *)malloc(2);
	if (ret == NULL)
		return (NULL);
	ret[0] = va_arg(*ap, int);
	ret[1] = NULL;
	return (ret);
}

char	*s_result(t_info *info, va_list *ap)
{
	int		i;
	char	*str_temp;
	char	*ret;

	i = 0;
	str_temp = va_arg(*ap, char *);
	if (str_temp == NULL)
		str_temp = "(null)";
	ret = (char *)malloc(ft_strlen(str_temp) + 1);
	if (ret == NULL)
		return (NULL);
	while (str_temp[i])
		ret[i] = str_temp[i++];
	ret[i] = NULL;
	return (ret);
}

char	*p_result(t_info *info, va_list *ap)
{
	int			length;
	long long	addr;
	char		*base_list;
	char		*ret;

	addr = va_arg(*ap, unsigned long);
	base_list = "0123456789abcdef";
	length = calc_length(16, addr);
	length += 2;
	ret = (char *)malloc(length + 1);
	if (ret == NULL)
		return (NULL);
	ret[length] = NULL;
	ret[0] = '0';
	ret[1] = 'x';
	while (--length > 1)
	{
		ret[length] = base_list[addr / 16];
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

	num = va_arg(*ap, int);
	if (num < 0 || info->plus_flag || info->space_flag)
		length++;
	ret1 = (char *)malloc(length + 1);
	if (ret1 == NULL)
		return (NULL);
	ret1[length] = NULL;
	if (num < 0)
		ret1[0] = '-';
	else if (num >= 0 && info->space_flag)
		ret1[0] = ' ';
	else if (num >= 0 && info->plus_flag)
		ret1[0] = '+';
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

	num = va_arg(*ap, unsigned int);
	if (num < 0 || info->plus_flag || info->space_flag)
		length++;
	ret1 = (char *)malloc(length + 1);
	if (ret1 == NULL)
		return (NULL);
	ret1[length] = NULL;
	if (num < 0)
		ret1[0] = '-';
	else if (num >= 0 && info->space_flag)
		ret1[0] = ' ';
	else if (num >= 0 && info->plus_flag)
		ret1[0] = '+';
	ret2 = write_num(10, num, info->precision);
	ret = ft_strjoin(ret1, ret2);
	free_all(ret1, ret2);
	return (ret);
}
