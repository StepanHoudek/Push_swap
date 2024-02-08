/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:44 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/08 15:11:19 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(void)
{
	t_struct	*node_a;
	t_struct	*node_b;

	node_a = NULL;
	ft_lstadd_start(&node_a, 2);
	while (node_a != NULL)
	{
		printf("%d\n", node_a->x);
		node_a = node_a->next;
	}
	return ;
}

int	main(void)
{
	push_swap();
}
