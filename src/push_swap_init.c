/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:16:45 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 18:41:33 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data, char **argv)
{
	ft_memset(data, 0, sizeof(t_data));
	init_raw_num(data, argv);
	data->len = ft_strarr_len(data->raw_num);
	check_valid(data);
	init_stack(data);
	init_tgt(data);
	init_func(data);
}

void	init_stack(t_data *data)
{
	int		i;
	t_ps	*node;
	t_ps	*prev;

	i = 0;
	while (i < data->len)
	{
		node = ft_calloc(1, sizeof(t_ps));
		if (node == NULL)
			free_exit(data, "Error\n", 1);
		node->num = ft_atoi(data->raw_num[i]);
		node->tgt = -1;
		if (i == 0)
			data->stack_a.first = node;
		else
			prev->next = node;
		prev = node;
		i++;
	}
	data->stack_a.last = node;
	data->stack_a.size = data->len;
}

void	init_tgt(t_data *data)
{
	int		i;
	t_ps	*temp;
	t_ps	*min;

	i = 0;
	while (i < data->stack_a.size)
	{
		temp = data->stack_a.first;
		while (temp != NULL && temp->tgt != -1)
			temp = temp->next;
		min = temp;
		while (temp != NULL)
		{
			if (temp->tgt == -1 && temp->num < min->num)
				min = temp;
			temp = temp->next;
		}
		min->tgt = i;
		i++;
	}
}

void	init_raw_num(t_data *data, char **argv)
{
	char	*temp;

	temp = ft_flatten(argv + 1, " ");
	if (temp == NULL)
		free_exit(data, "Error\n", 1);
	data->raw_num = ft_split(temp, ' ');
	if (data->raw_num == NULL)
	{
		free(temp);
		free_exit(data, "Error\n", 1);
	}
	free(temp);
}

void	init_func(t_data *data)
{
	data->ft = ft_calloc(11, sizeof(void (*)(t_stack *, t_stack *, int)));
	if (data->ft == NULL)
		free_exit(data, "Error\n", 1);
	data->ft[SA] = sa;
	data->ft[SB] = sb;
	data->ft[SS] = ss;
	data->ft[PA] = pa;
	data->ft[PB] = pb;
	data->ft[RA] = ra;
	data->ft[RB] = rb;
	data->ft[RR] = rr;
	data->ft[RRA] = rra;
	data->ft[RRB] = rrb;
	data->ft[RRR] = rrr;
	data->sort = ft_calloc(6, sizeof(void (*)(t_data *)));
	data->sort[2] = sort_two;
	data->sort[3] = sort_three;
	data->sort[4] = sort_four;
	data->sort[5] = sort_five;
}
