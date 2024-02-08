/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeallocate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:17:55 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 14:14:00 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstdeallocate(t_list **root)
{
	t_list	*curr;
	t_list	*next;

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
