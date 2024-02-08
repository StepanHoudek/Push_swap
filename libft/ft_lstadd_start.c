/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:17:00 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 13:27:47 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstadd_start(t_list **root, int value)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->x = value;
	new_node->next = NULL;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	new_node->next = *root;
	*root = new_node;
	return ;
}
