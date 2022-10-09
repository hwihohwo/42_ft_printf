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
	char	*ret;


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