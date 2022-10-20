/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:22:00 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/20 15:47:47 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char c, char *specifier)
{
	int	i;

	i = 0;
	while (specifier[i])
	{
		if (c == specifier[i])
			return (1);
		i++;
	}
	return (0);
}

char	*make_tmp(int count, const char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(count + 1);
	if (ret == NULL)
		return (NULL);
	while (i < count)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	count_string_length(const char *str, int j)
{
	if (str[j] == '%')
	{
		j++;
		while (!is_specifier(str[j], "cspdiuxX%") && str[j])
			j++;
		j++;
	}
	else
		while (str[j] != '%' && str[j])
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
	buffer = NULL;
	while (str[i])
	{
		j = count_string_length(str, j);
		tmp = make_tmp(j - i, &str[i]);
		if (tmp == NULL)
			return (NULL);
		i = j;
		ft_lstadd_back(&buffer, ft_lstnew(tmp));
	}
	return (buffer);
}
