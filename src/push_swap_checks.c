/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:37:16 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 18:41:23 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_valid(t_data *data)
{
	int	i;

	i = 0;
	if (data->len == 0)
		free_exit(data, "Error\n", 1);
	while (i < data->len)
	{
		if (ft_valid_int(data->raw_num[i]) == 0)
			free_exit(data, "Error\n", 1);
		i++;
	}
}

// return 1 if dupe, 0 if no dupe
int	check_dupe(t_data *data)
{
	t_ps	*temp_a;
	t_ps	*temp_b;

	temp_a = data->stack_a.first;
	while (temp_a != NULL)
	{
		temp_b = temp_a->next;
		while (temp_b != NULL)
		{
			if (temp_b->num == temp_a->num)
				return (1);
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	return (0);
}

// returns 1 if sorted, 0 if unsorted
int	check_sorted(t_data *data)
{
	t_ps	*temp;

	temp = data->stack_a.first;
	while (temp->next != NULL)
	{
		if (temp->tgt + 1 != temp->next->tgt)
			return (0);
		temp = temp->next;
	}
	return (1);
}

// returns -1 if none, 0 if sa, 1 if sb, 2 if ss.
// only checks if next->tgt is exactly +1, not just bigger
int	check_swap(t_data *data)
{
	int	i;

	i = -1;
	if (data->stack_a.first != NULL && data->stack_a.first->next != NULL)
	{
		if (data->stack_a.first->tgt - 1 == data->stack_a.first->next->tgt)
			i += 1;
	}
	if (data->stack_b.first != NULL && data->stack_b.first->next != NULL)
	{
		if (data->stack_b.first->tgt + 1 == data->stack_b.first->next->tgt)
			i += 2;
	}
	return (i);
}

// count how many in current stack a is unsorted, exact match in pairs.
int	check_uns(t_data *data)
{
	t_ps	*temp;
	int		count;

	temp = data->stack_a.first;
	count = 0;
	while (temp->next != NULL)
	{
		if (temp->tgt + 1 != temp->next->tgt)
			count++;
		temp = temp->next;
	}
	return (count);
}
