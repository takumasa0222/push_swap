/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:16:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/01 18:00:03 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	init(int **int_arry, int len)
{
	int			op_arry[10000];
	t_stack_inf	*stack_inf;
	t_ope_inf	*op_inf;

	init_stack_inf(&stack_inf);
	op_inf = malloc(1 * sizeof(t_ope_inf));
	if (!stack_inf || !op_inf)
	{
		free(*int_arry);
		throw_err(stack_inf, op_inf, MEM_ALLOC_ERR);
	}
	op_inf->i = 0;
	stack_inf->ope_inf = op_inf;
	stack_inf->ope_inf->op_arry = op_arry;
	stack_inf->original_arry = copy_arry(*int_arry, len, stack_inf);
	init_stack(stack_inf, stack_inf->original_arry, len, *int_arry);
	create_index(int_arry, len, stack_inf);
	stack_inf->sorted_arry = *int_arry;
	stack_inf->arry_len = len;
	push_swap(stack_inf);
	optimize_ope(stack_inf->ope_inf);
	describe_ope(stack_inf->ope_inf);
	free_stack_inf(stack_inf);
}

void	init_stack_inf(t_stack_inf **stack_inf)
{
	*stack_inf = malloc(1 * sizeof(t_stack_inf));
	(*stack_inf)->ope_inf = NULL;
	(*stack_inf)->stack_a = NULL;
	(*stack_inf)->stack_b = NULL;
	(*stack_inf)->original_arry = NULL;
	(*stack_inf)->sorted_arry = NULL;
}

int	push_swap(t_stack_inf *stack_inf)
{
	int	lst_size;

	lst_size = stack_inf->arry_len;
	if (is_arry_sorted(stack_inf, A_TOP, lst_size))
		return (0);
	if (1 < lst_size && lst_size <= 3)
		basic_sort(stack_inf, A_TOP, lst_size);
	else if (3 < lst_size)
		split_chunk(stack_inf, A_TOP, lst_size / 3, lst_size);
	else
		throw_err(stack_inf, NULL, MEM_ALLOC_ERR);
	return (0);
}

void	split_chunk(t_stack_inf *stack_inf, int pos, int index, int u_num)
{
	int	s_idx;
	int	n_unum;
	int	a_position;

	if (u_num <= 3 || is_arry_sorted(stack_inf, pos, u_num))
	{
		if (!is_arry_sorted(stack_inf, pos, u_num))
			basic_sort(stack_inf, pos, u_num);
		else
			move_chank_to_a_top(stack_inf, pos, u_num);
		return ;
	}
	split_operation(stack_inf, pos, index, u_num);
	s_idx = index + u_num / 3;
	n_unum = u_num / 3;
	a_position = A_BOTTOM;
	if (ft_lstsize(stack_inf->stack_a) <= n_unum + u_num % 3)
		a_position = A_TOP;
	split_chunk(stack_inf, a_position, s_idx + (n_unum + u_num % 3) / 3, n_unum \
	+ u_num % 3);
	split_chunk(stack_inf, B_TOP, index + n_unum / 3, n_unum);
	split_chunk(stack_inf, B_BOTTOM, index - (n_unum - n_unum / 3), n_unum);
}

void	split_operation(t_stack_inf *stack_inf, int pos, int index, int u_num)
{
	int	i;
	int	j;
	int	t_num;

	if (!stack_inf)
		throw_err(stack_inf, NULL, NULL_ERR);
	i = 0;
	j = 0;
	while (i < u_num)
	{
		t_num = take_first_elem(stack_inf, pos, 0);
		if (t_num < stack_inf->sorted_arry[index])
			move_to_b_bottom(stack_inf, pos);
		else if (stack_inf->sorted_arry[index + u_num / 3] <= t_num)
			move_to_a_bottom(stack_inf, pos);
		else
			move_to_b_top(stack_inf, pos);
		if (pos != A_TOP && take_first_elem(stack_inf, pos, t_num) == t_num)
		{
			move_to_a_top(stack_inf, pos);
			j++;
		}
		i++;
	}
	move_back(stack_inf, pos, j);
}
