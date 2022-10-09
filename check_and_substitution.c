/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:14:30 by seonghwc          #+#    #+#             */
/*   Updated: 2022/09/30 00:43:56 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	check_and_substitution(t_list *buffer, t_info *info, va_list ap)
{
	char	*str;
	t_list	*temp;

	temp = buffer;
	while (temp)
	{
		if (((char *)temp->content)[0] == '%')
		{
			str = (char *)temp->content;
			input_info(str, info);
			substitution(temp->content, info, ap);
		}
		temp = temp->next;
	}
}