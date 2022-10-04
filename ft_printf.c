/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:59:33 by seonghwc          #+#    #+#             */
/*   Updated: 2022/09/29 23:23:39 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_list	*buffer;
	t_flags	flags;
	va_list	ap;

	va_start(ap, str);
	buffer = NULL;
	buffer = make_buffer(str);
	if (buffer == NULL)
		return (0);
}
