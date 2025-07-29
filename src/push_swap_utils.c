/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:15:56 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 15:40:43 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_data *data, char *message, int exit_code)
{
	if (message != NULL)
		write(2, message, ft_strlen(message));
	if (data->stack_a.first != NULL)
		free_list(&data->stack_a.first);
	if (data->stack_b.first != NULL)
		free_list(&data->stack_b.first);
	if (data->ft != NULL)
		free (data->ft);
	if (data->sort != NULL)
		free (data->sort);
	ft_free_str_arr(data->raw_num);
	exit(exit_code);
}

void	free_list(t_ps **lst)
{
	t_ps	*temp;

	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
