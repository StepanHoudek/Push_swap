/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeallocate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:17:55 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 14:19:18 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstdeallocate(t_struct **root)
{
	t_struct	*curr;
	t_struct	*next;

	curr = *root;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*root = NULL;
	return ;
}
