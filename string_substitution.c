/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_substitution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:56:03 by marvin            #+#    #+#             */
/*   Updated: 2022/10/20 22:39:07 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_essential_string(t_info *info, va_list *ap)
{
	char	*result;

	if (info->c_flag == 1)
		result = c_result(ap, info);
	else if (info->s_flag == 1)
		result = s_result(ap, info);
	else if (info->p_flag == 1)
		result = p_result(ap);
	else if (info->d_flag == 1)
		result = d_result(info, ap);
	else if (info->i_flag == 1)
		result = d_result(info, ap);
	else if (info->u_flag == 1)
		result = u_result(info, ap);
	else if (info->low_x_flag == 1)
		result = low_x_result(info, ap);
	else if (info->x_flag == 1)
		result = x_result(info, ap);
	else
		result = percent_result();
	if (result == NULL)
		return (NULL);
	return (result);
}

char	*make_width(t_info *info, int essential_length)
{
	int		i;
	char	*ret;

	i = 0;
	if (info->width > essential_length)
	{
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
	}
	else
	{
		ret = (char *)malloc(1);
		if (ret == NULL)
			return (NULL);
		ret[0] = 0;
	}
	return (ret);
}

char	*make_string(t_info *info, va_list *ap)
{
	char	*ret1;
	char	*ret2;
	char	*ret;

	ret1 = make_essential_string(info, ap);
	if (ret1 == NULL)
		return (NULL);
	if (info->c_flag == 1 && ret[0] == '\0')
		ret2 = make_width(info, 1);
	else
		ret2 = make_width(info, ft_strlen(ret1));
	if (ret2 == NULL)
		return (NULL);
	if (info->minus_flag == 1)
		ret = ft_strjoin(ret1, ret2);
	else
		ret = ft_strjoin(ret2, ret1);
	free_all(ret1, ret2);
	return (ret);
}
