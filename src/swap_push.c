/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:44:41 by joloo             #+#    #+#             */
/*   Updated: 2025/05/20 18:32:47 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
void	sa(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (a->first == NULL || a->first->next == NULL)
		return ;
	(void)b;
	temp = a->first->next;
	a->first->next = temp->next;
	temp->next = a->first;
	a->first = temp;
	if (a->first->next->next == NULL)
	{
		a->last = a->first->next;
	}
	if (print == 1)
		ft_printf("%s\n", "sa");
}

// Swap the first 2 elements at the top of stack b.
void	sb(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (b->first == NULL || b->first->next == NULL)
		return ;
	(void)a;
	temp = b->first->next;
	b->first->next = temp->next;
	temp->next = b->first;
	b->first = temp;
	if (b->first->next->next == NULL)
	{
		b->last = b->first->next;
	}
	if (print == 1)
		ft_printf("%s\n", "sb");
}

// Take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (a->first == NULL)
		return ;
	temp = a->first;
	a->first = a->first->next;
	if (a->first == NULL)
		a->last = NULL;
	temp->next = b->first;
	b->first = temp;
	if (b->first->next == NULL)
		b->last = b->first;
	a->size--;
	b->size++;
	if (print == 1)
		ft_printf("%s\n", "pb");
}

// Take the first element at the top of b and put it at the top of a
void	pa(t_stack *a, t_stack *b, int print)
{
	t_ps	*temp;

	if (b->first == NULL)
		return ;
	temp = b->first;
	b->first = b->first->next;
	if (b->first == NULL)
		b->last = NULL;
	temp->next = a->first;
	a->first = temp;
	if (a->first->next == NULL)
		a->last = a->first;
	b->size--;
	a->size++;
	if (print == 1)
		ft_printf("%s\n", "pa");
}
