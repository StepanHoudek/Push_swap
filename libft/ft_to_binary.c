/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:49:07 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 14:13:50 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_to_binary(unsigned int num)
{
	if (num < 2)
		ft_putnbr_fd(num, 1);
	else
	{
		ft_to_binary(num / 2);
		ft_to_binary(num - ((num / 2) * 2));
	}
}
