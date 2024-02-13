/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:44 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/13 16:46:40 by shoudek          ###   ########.fr       */
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
void	rra_rrb(t_struct **tail, t_struct **head)
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

void	rrr(t_struct **t_a, t_struct **h_a, t_struct **t_b, t_struct **h_b)
{
	rra_rrb(t_a, h_a);
	rra_rrb(t_b, h_b);
}

// swap the first 2 elements at the top of stack
// do nothing if ther's only one or no elements
void	sa_sb(t_struct **tail, t_struct **head)
{
	t_struct	*temp_head;

	if (*tail == *head)
		return ;
	if ((*tail)->next == *head)
	{
		temp_head = *head;
		*head = *tail;
		*tail = temp_head;
		(*tail)->next = *head;
		(*tail)->prev = NULL;
		(*head)->prev = *tail;
		(*head)->next = NULL;
		return ;
	}
	temp_head = *head;
	*head = (*head)->prev;
	temp_head->prev = (*head)->prev;
	temp_head->next = *head;
	temp_head->prev->next = temp_head;
	(*head)->prev = (*head)->next;
	(*head)->next = NULL;
	return ;
}

void	ra_rb(t_struct **tail, t_struct **head)
{
	t_struct	*temp_tail;

	temp_tail = *tail;
	(*head) = (*head)->prev;
	*tail = (*head)->next;
	(*head)->next = NULL;
	(*tail)->prev = NULL;
	(*tail)->next = temp_tail;
	temp_tail->prev = (*tail);
	return ;
}

void	rr(t_struct **t_a, t_struct **h_a, t_struct **t_b, t_struct **h_b)
{
	ra_rb(t_a, h_a);
	ra_rb(t_b, h_b);
	return ;
}

void	calc_price(t_struct *t_a, t_struct *h_a, t_struct *t_b, t_struct *h_b)
{
	if (h_a->x > h_b->x)
		h_a->price = 1;
	return ;
}

void	ft_sort_three(t_struct **t_a, t_struct **h_a)
{
	if ((*h_a)->x == ft_lstmin(*h_a) && (*t_a)->x == ft_lstmax(*h_a))
		return ;
	if ((*h_a)->x == ft_lstmin(*h_a))
	{
		sa_sb(t_a, h_a);
		ft_sort_three(t_a, h_a);
	}
	else if ((*h_a)->x == ft_lstmax(*h_a))
	{
		ra_rb(t_a, h_a);
		ft_sort_three(t_a, h_a);
	}
	else
		sa_sb(t_a, h_a);
	return ;
}


void	push_swap(void)
{
	t_struct	*tail_a;
	t_struct	*head_a;
	t_struct	*tail_b;
	t_struct	*head_b;
	t_struct	*curr;

	// only two elements in A?
	if (ft_lstsize(head_a) == 2)
	{
		if (head_a->x > tail_a->x)
		{
			sa_sb(&tail_a, &head_a);
			ft_printf("%s", "sa");
		}
	}
	// only three elements in A?
	if (ft_lstsize(head_a) == 3)









	tail_a = NULL;
	head_b = NULL;
	// init stack A
	ft_dublstinit(&tail_a, &head_a, 7);
	// push numbers to stack A
	ft_dublstadd_end(&head_a, 2);
	ft_dublstadd_end(&head_a, 1);
	//ft_dublstadd_end(&head_a, 8);
	// print stack_a from head to tail
	printf("Stack A original:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	//ra_rb(&tail_a, &head_a);
	ft_sort_three(&tail_a, &head_a);
	// print stack_a from head to tail
	printf("Stack A three sorted:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	sa_sb(&tail_a, &head_a);
	// print stack_a from head to tail
	printf("Stack A sa_sb:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	rra_rrb(&tail_a, &head_a);
	// print stack_a from head to tail
	printf("Stack A rra_rrb:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	ra_rb(&tail_a, &head_a);
	// print stack_a from head to tail
	printf("Stack A ra_rb:\n");
	curr = head_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	// push two numbers to stack_b
	pa_pb(&head_a, &head_b, &tail_b);
	pa_pb(&head_a, &head_b, &tail_b);
	// if tail is bigger than head, reverse
	if (head_b->x < tail_b->x)
		ra_rb(&tail_b, &head_b);
	// print stack_b
	printf("Stack B pa_pb dvakrat:\n");
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
