/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:30:36 by seonghwc          #+#    #+#             */
/*   Updated: 2022/10/18 21:55:15 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	int	a;
	int	b;

	a = printf("%-10u\n", -23);
	b = ft_printf("%-10u\n", -23);
	printf("%d\n%d\n", a, b);
	return (0);
}
