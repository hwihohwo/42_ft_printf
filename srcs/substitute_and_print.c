/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_and_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:14:30 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/22 22:34:17 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	substitute_and_print(t_list *buffer, t_info *info, va_list *ap)
{
	int		count;
	char	*str;
	t_list	*temp;

	temp = buffer;
	count = 0;
	while (temp)
	{
		if (((char *)temp->content)[0] == '%')
		{
			str = (char *)temp->content;
			input_info(str, info);
			free(temp->content);
			temp->content = make_string(info, ap);
			if (temp->content == NULL)
				return (-1);
			info->length += ft_strlen((char *)temp->content);
		}
		else
			info->length = ft_strlen((char *)temp->content);
		count += print((char *)temp->content, info);
		temp = temp->next;
	}
	return (count);
}

int	print(char *str, t_info *info)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (info->length)
	{
		if (info->c_null_flag == 1)
		{
			check_c_null_flag(info, str, i);
			i--;
		}
		else if (info->d_zero_flag == 1 && str[i] == '0')
		{
			info->d_zero_flag = 0;
			count--;
		}
		else
			write(1, &str[i], 1);
		count++;
		info->length--;
		i++;
	}
	return (count);
}
