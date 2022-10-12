/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_result2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:56:52 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/12 19:56:13 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*low_x_result(t_info *info, va_list *ap)
{
	unsigned int	num;
	char			*ret1;
	char			*ret2;
	char			*ret;
	int				length;

	length = 0;
	num = va_arg(*ap, int);
	if (info->shap_flag == 1)
		length += 2;
	ret1 = (char *)malloc(length + 1);
	if (ret1 == NULL)
		return (NULL);
	ret1[length] = NULL;
	if (info->shap_flag == 1)
	{
		ret1[0] = '0';
		ret1[1] = 'x';
	}
	ret2 = write_num(16, num, info->precision);
	ret = ft_strjoin(ret1, ret2);
	free_all(ret1, ret2);
	return (ret);
}

char	*x_result(t_info *info, va_list *ap)
{
	unsigned int	num;
	char			*ret1;
	char			*ret2;
	char			*ret;
	int				length;

	length = 0;
	num = va_arg(*ap, int);
	if (info->shap_flag == 1)
		length += 2;
	ret1 = (char *)malloc(length + 1);
	if (ret1 == NULL)
		return (NULL);
	ret1[length] = NULL;
	if (info->shap_flag == 1)
	{
		ret1[0] = '0';
		ret1[1] = 'X';
	}
	ret2 = write_num_upper(16, num, info->precision);
	ret = ft_strjoin(ret1, ret2);
	free_all(ret1, ret2);
	return (ret);
}

char	*percent_result(void)
{
	char	*ret;

	ret = (char *)malloc(2);
	ret[0] = '%';
	ret[1] = NULL;
	return (ret);
}
