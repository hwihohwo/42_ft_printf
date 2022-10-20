/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:30:36 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/20 22:42:50 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	a;
	int	b;

	a = printf("%-1c%-2c%-3c\n", '0', 0, '1');
	b = ft_printf("%-1c%-2c%-3c\n", '0', 0, '1');
	printf("%d %d\n", a, b);
	return (0);
}
