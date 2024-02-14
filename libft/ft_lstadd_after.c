/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:17:32 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 13:55:29 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_after(t_str *node, int value)
{
	t_str	*new_node;

	new_node = malloc(sizeof(t_str));
	if (!new_node)
		return ;
	new_node->x = value;
	new_node->next = NULL;
	if (node == NULL)
	{
		node = new_node;
		return ;
	}
	new_node->next = node->next;
	node->next = new_node;
	return ;
}
