/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:44 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 16:39:23 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push from stack to stack
void	pa_pb(t_str **head_a, t_str **head_b, t_str **tail_b)
{
	t_str	*temp;

	if (*head_a == NULL)
		return ;
	temp = (*head_a)->prev;
	if ((*head_b) == NULL)
	{
		*head_b = *head_a;
		*tail_b = *head_a;
		(*head_b)->prev = NULL;
	}
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

void	pa(t_str **head_b, t_str **head_a, t_str **tail_a)
{
	pa_pb(head_b, head_a, tail_a);
	ft_printf("pa\n");
	return ;
}

void	pb(t_str **head_a, t_str **head_b, t_str **tail_b)
{
	pa_pb(head_a, head_b, tail_b);
	ft_printf("pb\n");
	return ;
}

// rotate stack
void	rra_rrb(t_str **tail, t_str **head)
{
	t_str	*temp_head;

	temp_head = *head;
	(*tail) = (*tail)->next;
	*head = (*tail)->prev;
	(*tail)->prev = NULL;
	(*head)->next = NULL;
	(*head)->prev = temp_head;
	temp_head->next = (*head);
	return ;
}

void	rra(t_str **tail, t_str **head)
{
	rra_rrb(tail, head);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_str **tail, t_str **head)
{
	rra_rrb(tail, head);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_str **t_a, t_str **h_a, t_str **t_b, t_str **h_b)
{
	rra_rrb(t_a, h_a);
	rra_rrb(t_b, h_b);
	ft_printf("rrr\n");
	return ;
}

// swap the first 2 elements at the top of stack
// do nothing if there's only one or no elements
void	sa_sb(t_str **tail, t_str **head)
{
	t_str	*temp_head;

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

void	sa(t_str **tail, t_str **head)
{
	sa_sb(tail, head);
	ft_printf("sa\n");
	return ;
}

void	sb(t_str **tail, t_str **head)
{
	sa_sb(tail, head);
	ft_printf("sb\n");
	return ;
}

void	ra_rb(t_str **tail, t_str **head)
{
	t_str	*temp_tail;

	temp_tail = *tail;
	(*head) = (*head)->prev;
	*tail = (*head)->next;
	(*head)->next = NULL;
	(*tail)->prev = NULL;
	(*tail)->next = temp_tail;
	temp_tail->prev = (*tail);
	return ;
}

void	ra(t_str **tail, t_str **head)
{
	ra_rb(tail, head);
	ft_printf("ra\n");
	return ;
}

void	rb(t_str **tail, t_str **head)
{
	ra_rb(tail, head);
	ft_printf("rb\n");
	return ;
}

void	rr(t_str **t_a, t_str **h_a, t_str **t_b, t_str **h_b)
{
	ra_rb(t_a, h_a);
	ra_rb(t_b, h_b);
	ft_printf("rr\n");
	return ;
}

void	ft_sort_three_a(t_str **t_a, t_str **h_a)
{
	if ((*h_a)->x == ft_lstmin(*h_a) && (*t_a)->x == ft_lstmax(*h_a))
		return ;
	if ((*h_a)->x == ft_lstmin(*h_a))
	{
		sa(t_a, h_a);
		ft_sort_three_a(t_a, h_a);
	}
	else if ((*h_a)->x == ft_lstmax(*h_a))
	{
		ra(t_a, h_a);
		ft_sort_three_a(t_a, h_a);
	}
	else
		sa(t_a, h_a);
	return ;
}

void	calculate_node_price(t_str *node, t_str *tail, t_str *head)
{
	node->r_price = ft_lstpricer(node, head);
	node->rr_price = ft_lstpricerr(node, tail);
	return ;
}

void	calculate_ttl_node_price(t_str *node_a, t_str *node_b)
{
	int	price;

	price = 0;
	if (node_a->r_price < node_a->rr_price)
		price += node_a->r_price;
	else
		price += node_a->rr_price;
	if (node_b->r_price < node_b->rr_price)
		price += node_b->r_price;
	else
		price += node_b->rr_price;
	node_a->ttl_price = price;
	return ;
}

void	calculate_stack_price(t_str *t_a, t_str *h_a, t_str *t_b, t_str *h_b)
{
	t_str	*curr_a;
	t_str	*curr_b;
	t_str	*cheapest;

	curr_a = h_a;
	while (curr_a != NULL)
	{
		// element on top of A and element biggest in B?
		if (curr_a == h_a && curr_a->x >= ft_lstmax(h_b))
		{
			curr_a = curr_a->prev;
			pb(&h_a, &h_b, &t_b);
			continue ;
		}
		// element on top of A and element smallest in B?
		if (curr_a == h_a && curr_a->x <= ft_lstmin(h_b))
		{
			curr_a = curr_a->prev;
			pb(&h_a, &h_b, &t_b);
			rb(&t_b, &h_b);
			continue ;
		}
		// Look for a node in B from head after which element fits
		curr_a->node_b = ft_lstfindfit(curr_a, h_b);
		// calculate A element
		calculate_node_price(curr_a, t_a, h_a);
		// calculate B node
		calculate_node_price(curr_a->node_b, t_b, h_b);
		// calculate total lowest price for pushing the element
		calculate_ttl_node_price(curr_a, curr_a->node_b);
		// then operate
		curr_a = curr_a->prev;
	}
}

// void	operate(t_str *node_a, t_str *node_b)
// {
// 	t_str	*cheapest;
// 	// choose the element with the lowest price
// 	cheapest = ft_findlowestprice(h_a);
// 	// perform operations on A
// 	if (curr_a->r_price > curr_a->rr_price)
// 	{
// 		while (curr_a->rr_price--)
// 			rra(&t_a, &h_a);
// 	}
// 	else
// 	{
// 		while (curr_a->r_price--)
// 			ra(&t_a, &h_a);
// 	}
// 	// perform operations on B
// 	if (curr_b->r_price > curr_b->rr_price)
// 	{
// 		while (curr_b->rr_price--)
// 			rrb(&t_b, &h_b);
// 	}
// 	else
// 	{
// 		while (curr_b->r_price--)
// 			rb(&t_b, &h_b);
// 	}
// 	pb (&h_a, &h_b, &t_b);
// }

void	print_stack(t_str *head)
{
	while (head != NULL)
	{
		ft_printf("Val: %d | ttl: %d | rr: %d | r: %d\n", head->x,
			head->ttl_price, head->rr_price, head->r_price);
		head = head->prev;
	}
	return ;
}

void	push_swap(void)
{
	t_str	*tail_a;
	t_str	*head_a;
	t_str	*tail_b;
	t_str	*head_b;
	t_str	*curr_a;
	t_str	*curr_b;
	t_str	*cheapest;

	head_b = NULL;
	// init stack A
	ft_dublstinit(&tail_a, &head_a, 4);
	ft_dublstadd_end(&head_a, 2);
	ft_dublstadd_end(&head_a, 3);
	ft_dublstadd_end(&head_a, 1);
	ft_dublstadd_end(&head_a, 100);
	ft_dublstadd_end(&head_a, 200);
	print_stack(head_a);
	// only two elements in A?
	if (ft_lstsize(head_a) == 2)
	{
		if (head_a->x > tail_a->x)
			sa(&tail_a, &head_a);
		return ;
	}
	// only three elements in A?
	if (ft_lstsize(head_a) == 3)
	{
		ft_sort_three_a(&tail_a, &head_a);
		return ;
	}
	// PB 2*
	pb(&head_a, &head_b, &tail_b);
	pb(&head_a, &head_b, &tail_b);
	printf("Stack A: \n");
	print_stack(head_a);
	printf("Stack B: \n");
	print_stack(head_b);
	if (head_b->x < tail_b->x)
		sb(&tail_b, &head_b);
	printf("Stack B: \n");
	print_stack(head_b);
	// calculate
	calculate_stack_price(tail_a, head_a, tail_b, head_b);
	printf("Stack A: \n");
	print_stack(head_a);
	// operate
	// operate();
	return ;
}

int	main(void)
{
	push_swap();
}
