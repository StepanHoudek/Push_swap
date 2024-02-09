/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:44 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/09 14:23:58 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push from stack to stack
void	pa_pb(t_struct **head_a, t_struct **head_b, t_struct **tail_b)
{
	t_struct	*temp;

	// if there's nothing on stack_a to pop
	if (*head_a == NULL)
		return ;
	temp = (*head_a)->prev;
	// if there's nothing on stack b
	if ((*head_b) == NULL) 
	{
	// push the node from A to start of B
		*head_b = *head_a;
		*tail_b = *head_a;
		(*head_b)->prev = NULL;
	}
	// if there's something on stack b
	else
	{
		(*head_a)->prev = (*head_b);
		(*head_b)->next = (*head_a);
		*head_b = *head_a;
	}
	(*head_a) = temp;
	(*head_a)->next = NULL;
	return ;
}

// rotate stack
void	ra_rb(t_struct **tail, t_struct **head)
{
	t_struct	*temp_head;

	temp_head = *head;
	(*tail) = (*tail)->next;
	*head = (*tail)->prev;
	(*tail)->prev = NULL;
	(*head)->next = NULL;
	(*head)->prev = temp_head;
	temp_head->next = (*head);
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
	head_b = NULL;
	// init stack A
	ft_dublstinit(&tail_a, &head_a, 3);
	// push numbers to stack A
	ft_dublstadd_start(&tail_a, 8);
	ft_dublstadd_start(&tail_a, 4); 
	ft_dublstadd_start(&tail_a, 9);
	// print stack_a from head to tail
	printf("Stack A:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	// rotate stack A
	ra_rb(&tail_a, &head_a);
	// print stack_a
	printf("Stack A:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	// push a number to stack_b
	pa_pb(&head_a, &head_b, &tail_b);
	// print stack_b
	printf("Stack B:\n");
	curr = head_b;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	// print stack_a
	printf("Stack A:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	// push a number to stack_b
	pa_pb(&head_a, &head_b, &tail_b);
	// print stack_b
	printf("Stack B:\n");
	curr = head_b;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	// print stack_a
	printf("Stack A:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	// deallocate both stacks
	ft_dublstdeallocate(&tail_a, &head_a);
	ft_dublstdeallocate(&tail_b, &head_b);
	return ;
}

int	main(void)
{
	push_swap();
}
