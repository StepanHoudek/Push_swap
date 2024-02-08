/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:21 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 14:57:04 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_struct **root, int value)
{
	t_struct	*new_node;
	t_struct	*curr;

	new_node = malloc(sizeof(t_struct));
	if (!new_node)
		return ;
	new_node->x = value;
	new_node->next = NULL;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	return ;
}
