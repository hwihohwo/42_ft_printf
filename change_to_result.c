/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:11:18 by marvin            #+#    #+#             */
/*   Updated: 2022/10/10 18:11:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

char	*c_result(t_info *info, va_list temp)
{
	char	*ret;

	ret = (char *)malloc(2);
	if (ret == NULL)
		return (NULL);
	ret[0] = va_arg(temp, int);
	ret[1] = NULL;
	return (ret);
}

char	*s_result(t_info *info, va_list temp)
{
	int		i;
	char	*str_temp;
	char	*ret;

	i = 0;
	str_temp = va_arg(temp, char *);
	if (info->precision > 0)
	{
		ret = (char *)malloc(info->precision + 1);
		ret[info->precision] = NULL;
	}
	else
	{
		ret = (char *)malloc(ft_strlen(str_temp) + 1);
		ret[ft_strlen(str_temp)] = NULL;
	}
	if (ret == NULL)
		return (NULL);
	while (ret[i] && str_temp[i])
		ret[i] = str_temp[i++];
	return (ret);
}

char	*p_result(t_info *info, va_list temp)
{
	
}