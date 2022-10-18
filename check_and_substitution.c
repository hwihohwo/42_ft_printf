/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_substitution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:14:30 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/18 21:37:37 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	check_and_substitution(t_list *buffer, t_info *info, va_list *ap)
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
			free(temp->content);
			temp->content = make_string(info, ap);
			if (temp->content == NULL)
				return ;
		}
		temp = temp->next;
	}
}

int	print_all(t_list *buffer)
{
	int		i;
	int		count;

	count = 0;
	while (buffer)
	{
		i = 0;
		while (((char *)buffer->content)[i])
		{
			write(1, &buffer->content[i++], 1);
			count++;
		}
		buffer = buffer->next;
	}
	return (count);
}
