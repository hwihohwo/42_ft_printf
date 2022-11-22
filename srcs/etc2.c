/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:38:45 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/22 22:35:22 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_flag(char *ret)
{
	int		i;
	char	temp;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '-' || ret[i] == ' ' || ret[i] == '+')
		{
			temp = ret[i];
			ret[i] = ret[0];
			ret[0] = temp;
		}
		else if (ret[i] == 'x' || ret[i] == 'X')
		{
			temp = ret[i];
			ret[i] = ret[1];
			ret[1] = temp;
		}
		i++;
	}
}

void	check_c_null_flag(t_info *info, char *str, int i)
{
	if (info->minus_flag == 1)
	{
		write(1, "\0", 1);
		info->c_null_flag = 0;
	}
	else if (info->length <= 1)
	{
		write(1, "\0", 1);
		info->c_null_flag = 0;
	}
	else
		write(1, &str[i], 1);
}

char	*make_width_sub(t_info *info, int essential_length)
{
	char	*ret;
	int		i;

	i = 0;
	if (info->d_zero_flag == 1)
		info->width++;
	ret = (char *)malloc(info->width - essential_length + 1);
	if (ret == NULL)
		return (NULL);
	ret[info->width - essential_length] = 0;
	if (info->zero_flag == 1)
		while (info->width - essential_length - i)
			ret[i++] = '0';
	else
		while (info->width - essential_length - i)
			ret[i++] = ' ';
	return (ret);
}
