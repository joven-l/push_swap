/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:38:12 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 15:35:04 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// RRR cuz i can
void	sort_two(t_data *data)
{
	data->ft[RRR](&data->stack_a, &data->stack_b, 1);
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a.first->tgt;
	b = data->stack_a.first->next->tgt;
	c = data->stack_a.first->next->next->tgt;
	if (a < b && b < c)
		return ;
	if (a > b && a > c)
		data->ft[RA](&data->stack_a, &data->stack_b, 1);
	else if (b > a && b > c)
		data->ft[RRA](&data->stack_a, &data->stack_b, 1);
	if (check_swap(data) != -1)
		data->ft[check_swap(data)](&data->stack_a, &data->stack_b, 1);
}

void	sort_four(t_data *data)
{
	while (data->stack_a.size != 3)
	{
		if (data->stack_a.first->tgt == 0)
			data->ft[PB](&data->stack_a, &data->stack_b, 1);
		else
			data->ft[RA](&data->stack_a, &data->stack_b, 1);
	}
	sort_three(data);
	while (data->stack_b.size != 0)
		data->ft[PA](&data->stack_a, &data->stack_b, 1);
}

void	sort_five(t_data *data)
{
	while (data->stack_a.size != 3)
	{
		if (data->stack_a.first->tgt == 0 || data->stack_a.first->tgt == 1)
			data->ft[PB](&data->stack_a, &data->stack_b, 1);
		else
			data->ft[RA](&data->stack_a, &data->stack_b, 1);
	}
	sort_three(data);
	while (data->stack_b.size != 0)
		data->ft[PA](&data->stack_a, &data->stack_b, 1);
	if (check_swap(data) != -1)
		data->ft[check_swap(data)](&data->stack_a, &data->stack_b, 1);
}
