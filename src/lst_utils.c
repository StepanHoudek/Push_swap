/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:49:51 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/13 13:04:23 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstmin(t_struct *head)
{
	int	min;

	min = head->x;
	while (head != NULL)
	{
		if (head->x < min)
			min = head->x;
		head = head->prev;
	}
	return (min);
}

int	ft_lstmax(t_struct *head)
{
	int	max;

	max = head->x;
	while (head != NULL)
	{
		if (head->x > max)
			max = head->x;
		head = head->prev;
	}
	return (max);
}

int	ft_lstsize(t_struct *stack)
{
	return (0);
}