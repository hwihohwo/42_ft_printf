/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:38:45 by seonghwc          #+#    #+#             */
/*   Updated: 2022/11/17 18:46:41 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
