/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:38:45 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/21 14:42:30 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_flag(char *ret)
{
	int		i;
	char	temp;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '-')
		{
			temp = ret[i];
			ret[i] = ret[0];
			ret[0] = temp;
		}
		i++;
	}
}
