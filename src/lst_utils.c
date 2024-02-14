/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:49:51 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 11:25:15 by shoudek          ###   ########.fr       */
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

int	ft_lstsize(t_struct *head)
{
	int	size;

	size = 0;
	while (head != NULL)
	{
		size++;
		head = head->prev;
	}
	return (size);
}

int	ft_lstpricer(t_struct *node, t_struct *head)
{
	int	r_count;

	r_count = 0;
	while (node != head)
	{
		r_count++;
		node = node->next;
	}
	return (r_count);
}

int	ft_lstpricerr(t_struct *node, t_struct *tail)
{
	int	rr_count;

	rr_count = 1;
	while (node != tail)
	{
		rr_count++;
		node = node->prev;
	}
	return (rr_count);
}

t_struct	*ft_lstfindfit(t_struct *node, t_struct *head)
{
	t_struct	*curr;

	curr = head;
	while (node->x < curr->x)
		curr = curr->prev;
	return (curr);
}

void	ft_lstpushprice(t_struct *node)
{
	if (node->r_price < node->rr_price)
		node->node_price = node->r_price;
	else
		node->node_price = node->rr_price;
}