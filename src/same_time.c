/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:22:38 by joloo             #+#    #+#             */
/*   Updated: 2025/05/20 14:01:02 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, b, 0);
	sb(a, b, 0);
	if (print == 1)
		ft_printf("%s\n", "ss");
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, b, 0);
	rb(a, b, 0);
	if (print == 1)
		ft_printf("%s\n", "rr");
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, b, 0);
	rrb(a, b, 0);
	if (print == 1)
		ft_printf("%s\n", "rrr");
}
