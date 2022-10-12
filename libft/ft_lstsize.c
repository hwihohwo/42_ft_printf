/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:52:05 by seonghwc          #+#    #+#             */
/*   Updated: 2022/07/12 19:33:52 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		num;
	t_list	*temp;

	num = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		num++;
	}
	return (num);
}
