/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:59:33 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/12 19:22:05 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_info	info;
	t_list	*buffer;
	va_list	ap;
	int		count;

	va_start(ap, str);
	info.va_arg_num = 0;
	buffer = NULL;
	buffer = make_buffer(str, &info);
	if (buffer == NULL)
		return (0);
	check_and_substitution(buffer, &info, &ap);
	count = print_all(buffer);
	lst_clear(buffer, free);
	va_end(ap);
	return (count);
}
