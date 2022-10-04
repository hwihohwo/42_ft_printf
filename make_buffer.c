/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:22:00 by seonghwc          #+#    #+#             */
/*   Updated: 2022/09/30 00:44:17 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	is_specifier(char c, char *specifier)
{
	int	i;

	while (specifier[i])
		if (c == specifier[i])
			return (1);
	return (0);
}

char	*make_tmp(int count, char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(count + 1);
	if (ret == NULL)
		return (NULL);
	while (i < count)
		ret[i] = str[i++];
	ret[i] = NULL;
	return (ret);
}

int	count_string_length(char *str, int j)
{
	if (str[j] == '%')
	{
		j++;
		while (!is_specifier(str[j], g_specifier))
			j++;
		j++;
	}
	else
		while (str[j] != '%')
			j++;
	return (j);
}

t_list	*make_buffer(const char *str)
{
	int		i;
	int		j;
	char	*tmp;
	t_list	*buffer;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = count_string_length(&str[i], j);
		tmp = make_tmp(j - i, &str[i]);
		if (tmp == NULL)
			return (NULL);
		i = j;
		lst_addback(&buffer, lst_new(tmp));
	}
	return (buffer);
}
