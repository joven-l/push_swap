/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:25:04 by joloo             #+#    #+#             */
/*   Updated: 2025/05/20 14:00:49 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (a->first == NULL || a->first->next == NULL)
		return ;
	(void)b;
	temp = a->first;
	a->first = a->first->next;
	a->last->next = temp;
	a->last = temp;
	temp->next = NULL;
	if (print == 1)
		ft_printf("%s\n", "ra");
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (b->first == NULL || b->first->next == NULL)
		return ;
	(void)a;
	temp = b->first;
	b->first = b->first->next;
	b->last->next = temp;
	b->last = temp;
	temp->next = NULL;
	if (print == 1)
		ft_printf("%s\n", "rb");
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (a->first == NULL || a->first->next == NULL)
		return ;
	(void)b;
	temp = a->first;
	while (temp->next->next != NULL)
		temp = temp->next;
	a->last->next = a->first;
	a->first = a->last;
	a->last = temp;
	temp->next = NULL;
	if (print == 1)
		ft_printf("%s\n", "rra");
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (b->first == NULL || b->first->next == NULL)
		return ;
	(void)a;
	temp = b->first;
	while (temp->next->next != NULL)
		temp = temp->next;
	b->last->next = b->first;
	b->first = b->last;
	b->last = temp;
	temp->next = NULL;
	if (print == 1)
		ft_printf("%s\n", "rrb");
}
