/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:41:02 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 16:44:13 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sort(t_data *data)
{
	if (check_dupe(data) == 1)
		free_exit(data, "Error\n", 1);
	if (check_sorted(data) == 1)
		free_exit(data, NULL, 0);
	if (data->len <= 5)
		data->sort[data->len](data);
	else if (check_uns(data) <= 50)
		selection_sort(data);
	else
		radix_sort(data);
}

// data->len -1 because 0 indexing
void	radix_sort(t_data *data)
{
	int	bit;

	bit = 0;
	while (((data->len - 1) >> bit) != 0)
	{
		radix_sort_process(data, bit);
		if (check_sorted(data) == 1)
			break ;
		if (check_uns(data) <= 25)
		{
			selection_sort(data);
			break ;
		}
		bit++;
	}
}

void	radix_sort_process(t_data *data, int bit)
{
	int	j;

	j = data->stack_a.size;
	while (j > 0)
	{
		if (((data->stack_a.first->tgt >> bit) & 1) == 0)
			data->ft[PB](&data->stack_a, &data->stack_b, 1);
		else
			data->ft[RA](&data->stack_a, &data->stack_b, 1);
		j--;
	}
	while (data->stack_b.size != 0)
		data->ft[PA](&data->stack_a, &data->stack_b, 1);
}

// locates tgt = i and pb
void	selection_sort(t_data *data)
{
	int	i;
	int	rot;

	i = 0;
	while (i < data->len - 1)
	{
		rot = check_rot(data, i);
		while (data->stack_a.first->tgt != i)
			data->ft[rot](&data->stack_a, &data->stack_b, 1);
		if (check_sorted(data) == 1)
			break ;
		data->ft[PB](&data->stack_a, &data->stack_b, 1);
		i++;
	}
	while (data->stack_b.size != 0)
		data->ft[PA](&data->stack_a, &data->stack_b, 1);
}

// check if use ra or rra find target index in stack a
int	check_rot(t_data *data, int i)
{
	t_ps	*temp;
	int		count;

	temp = data->stack_a.first;
	count = 0;
	while (temp != NULL)
	{
		if (temp->tgt == i)
			break ;
		temp = temp->next;
		count++;
	}
	if (count * 2 >= data->len)
		return (RRA);
	return (RA);
}
