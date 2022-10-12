/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:50:47 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/12 19:10:31 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	calc_length(int base, long num)
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
	ret[length] = NULL;
	while (--length >= 0)
	{
		ret[length] = base_list[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	while (--length >= 0)
		ret[length] = 0;
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
	ret[length] = NULL;
	while (--length >= 0)
	{
		ret[length] = base_list[num % base];
		num /= base;
		if (num == 0)
			break ;
	}
	while (--length >= 0)
		ret[length] = 0;
	return (ret);
}

void	free_all(char *arr1, char *arr2)
{
	free(arr1);
	free(arr2);
}
