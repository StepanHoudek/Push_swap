/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:44 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/09 10:11:03 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_struct **head_a, t_struct **head_b)
{
	(*head_a)->prev->next = NULL;
	(*head_a)->prev = *head_b;
	(*head_b)->next = *head_a;
	return ;
}

void	ra(t_struct **tail_a, t_struct **head_a)
{
	(*tail_a)->prev = *head_a;
	(*tail_a)->next = NULL;
	(*head_a)->next = *tail_a;
	return ;
}

void	push_swap(void)
{
	t_struct	*tail_a;
	t_struct	*head_a;
	t_struct	*tail_b;
	t_struct	*head_b;
	t_struct	*curr;

	tail_a = NULL;
	// init stack A
	ft_dublstinit(&tail_a, &head_a, 3);
	ft_dublstadd_start(&tail_a, 8); // 8
	ft_dublstadd_start(&tail_a, 4); // 4 8
	ft_dublstadd_start(&tail_a, 9);
	// print stack_a
	printf("Stack A:\n");
	curr = tail_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	// rotate stack A
	ra(&tail_a, )
	// init stack B
	ft_dublstinit(&tail_b, &head_b, 6);
	printf("Stack B:\n");
	curr = tail_b;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	// push two numbers to stack_b
	pb(&head_a, &head_b);
	// print stack_b
	printf("Stack B:\n");
	curr = tail_b;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	// print stack_a
	printf("Stack A:\n");
	curr = tail_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	// free()
	ft_dublstdeallocate(&tail_a, &head_a);
	ft_dublstdeallocate(&tail_b, &head_b);
	return ;
}

int	main(void)
{
	push_swap();
}
