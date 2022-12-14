/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:59:33 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/23 18:49:28 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_info	info;
	t_list	*buffer;
	va_list	ap;
	int		count;

	va_start(ap, str);
	buffer = NULL;
	buffer = make_buffer(str);
	if (buffer == NULL)
	{
		ft_lstclear(&buffer, free);
		return (0);
	}
	count = substitute_and_print(buffer, &info, &ap);
	if (count == -1)
	{
		ft_lstclear(&buffer, free);
		return (0);
	}
	ft_lstclear(&buffer, free);
	va_end(ap);
	return (count);
}
