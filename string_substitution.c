/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_substitution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:56:03 by marvin            #+#    #+#             */
/*   Updated: 2022/10/08 17:56:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

char	*essential_string(t_info *info, va_list ap)
{
	// 각 specifier별로 적용되는 flag들 처리 고민 중.
	va_list	temp;
	int		length;

	length = 0;
	va_copy(temp, ap);
	if ((info->x_flag ==1 || info->low_x_flag == 1) && info->sharp_flag == 1)
		length += 2;
	length += info->precision;

}

char	*make_string(t_info *info, va_list ap)
{
	int		length;
	char	*ret;

	ret = essential_string(info, ap);
}

void	substitution(char *str, t_info *info, va_list ap)
{
	char	*ret;
	ret = make_string(info, ap);
}