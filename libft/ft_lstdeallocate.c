/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeallocate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:17:55 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 14:57:15 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeallocate(t_struct **root)
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
