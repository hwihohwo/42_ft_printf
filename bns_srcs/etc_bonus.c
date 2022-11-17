/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:50:47 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/17 18:46:37 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	calc_length(int base, unsigned long num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		length++;
	}
	return (length);
}

char	*write_num(int base, long num, int precision)
{
	char	*ret;
	int		length;
	char	*base_list;

	base_list = "0123456789abcdef";
	length = calc_length(base, num);
	if (precision > length)
		length = precision;
	ret = (char *)malloc(length + 1);
	if (ret == NULL)
		return (NULL);
	ret[length] = 0;
	while (--length >= 0)
	{
		ret[length] = base_list[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	while (--length >= 0)
		ret[length] = '0';
	return (ret);
}

char	*write_num_upper(int base, long num, int precision)
{
	char	*ret;
	int		length;
	char	*base_list;

	base_list = "0123456789ABCDEF";
	length = calc_length(base, num);
	if (precision > length)
		length = precision;
	ret = (char *)malloc(length + 1);
	if (ret == NULL)
		return (NULL);
	ret[length] = 0;
	while (--length >= 0)
	{
		ret[length] = base_list[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	while (--length >= 0)
		ret[length] = '0';
	return (ret);
}

void	free_all(char *arr1, char *arr2)
{
	free(arr1);
	free(arr2);
}

void	put_d_front(int num, char *ret1, t_info *info)
{
	if (num < 0)
		ret1[0] = '-';
	else if (num >= 0 && info->space_flag)
		ret1[0] = ' ';
	else if (num >= 0 && info->plus_flag)
		ret1[0] = '+';
}
