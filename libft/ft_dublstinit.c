/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dublstinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:41:05 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 09:35:04 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dublstinit(t_struct **tail, t_struct **head, int value)
{
	t_struct	*new_node;

	new_node = malloc(sizeof(t_struct));
	if (new_node == NULL)
		return ;
	new_node->x = value;
	new_node->r_price = 0;
	new_node->rr_price = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	*tail = new_node;
	*head = new_node;
}