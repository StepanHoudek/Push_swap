/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dublistadd_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:40:46 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:16 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dublstadd_end(t_struct **head, int value)
{
	t_struct	*new_node;

	new_node = malloc(sizeof(t_struct));
	if (new_node == NULL)
		return ;
	new_node->x = value;
	new_node->prev = *head;
	new_node->next = NULL;
	(*head)->next = new_node;
	*head = new_node;
	return ;
}