/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:20:49 by joloo             #+#    #+#             */
/*   Updated: 2025/05/26 16:41:17 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef enum e_ops
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_ops;

typedef struct s_data	t_data;

typedef struct s_ps
{
	int			num;
	int			tgt;
	struct s_ps	*next;
}	t_ps;

typedef struct s_stack
{
	t_ps	*first;
	t_ps	*last;
	int		size;
}	t_stack;

struct s_data
{
	void		(**ft)(t_stack *, t_stack *, int);
	void		(**sort)(t_data *data);
	char		**raw_num;
	int			len;
	t_stack		stack_a;
	t_stack		stack_b;
};

// low_sort.c
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);

// push_swap_checks.c
void	check_valid(t_data *data);
int		check_dupe(t_data *data);
int		check_sorted(t_data *data);
int		check_swap(t_data *data);
int		check_uns(t_data *data);

// push_swap_init.c
void	init_data(t_data *data, char **argv);
void	init_stack(t_data *data);
void	init_tgt(t_data *data);
void	init_raw_num(t_data *data, char **argv);
void	init_func(t_data *data);

// push_swap_utils.c
void	free_exit(t_data *data, char *message, int exit_code);
void	free_list(t_ps **lst);
void	print_list(t_data *data);

// rotates.c
void	ra(t_stack *a, t_stack *b, int print);
void	rb(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, t_stack *b, int print);
void	rrb(t_stack *a, t_stack *b, int print);

// same_time.c
void	ss(t_stack *a, t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);

// sorting.c
void	push_swap_sort(t_data *data);
void	radix_sort(t_data *data);
void	radix_sort_process(t_data *data, int bit);
void	selection_sort(t_data *data);
int		check_rot(t_data *data, int i);

// swap_push.c
void	sa(t_stack *a, t_stack *b, int print);
void	sb(t_stack *a, t_stack *b, int print);
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);

#endif