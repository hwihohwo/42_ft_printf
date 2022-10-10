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
	char	*result;

	va_copy(temp, ap);
	if (info->c_flag == 1)
		result = c_result(info, temp);
	if (info->s_flag == 1)
		result = s_result(info, temp);
	if (info->p_flag == 1)
		result = p_result(info, temp);
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