/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:49:51 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 16:30:42 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstmin(t_str *head)
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

int	ft_lstmax(t_str *head)
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

int	ft_lstsize(t_str *head)
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

int	ft_lstpricer(t_str *node, t_str *head)
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

int	ft_lstpricerr(t_str *node, t_str *tail)
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

t_str	*ft_lstfindfit(t_str *node, t_str *head)
{
	t_str	*curr;

	curr = head;
	while (node->x < curr->x)
		curr = curr->prev;
	return (curr);
}

t_str	*ft_findlowestprice(t_str *head)
{
	t_str	*lowest;

	lowest = head;
	while (head != NULL)
	{
		if (head->ttl_price < lowest->ttl_price)
			lowest = head;
		head = head->prev;
	}
	return (lowest);
}