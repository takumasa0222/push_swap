/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:16:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/29 04:51:51 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

#include <stdio.h>

void	init(int **int_arry, int len)
{
	int			op_arry[10000];
	t_stack_inf	*stack_inf;
	t_ope_inf	*op_inf;

	stack_inf = malloc(1 * sizeof(t_stack_inf));
	op_inf = malloc(1 * sizeof(t_ope_inf));
	if (!stack_inf || !op_inf)
	{
		free(*int_arry);
		throw_err(stack_inf, op_inf, MEM_ALLOC_ERR);
	}
	op_inf->i = 0;
	init_stack(stack_inf, *int_arry, len);
	stack_inf->ope_inf = op_inf;
	stack_inf->ope_inf->op_arry = op_arry;
	create_index(int_arry, len, stack_inf);
	stack_inf->sorted_arry = *int_arry;
	stack_inf->arry_len = len;
	
	t_list *temp_a = stack_inf->stack_a; 
	while (temp_a)
	{
		printf("value is %d\n",*((int*)temp_a->content));
		temp_a = temp_a->next;
	}
	// push_swap(stack_inf);
	// describe_ope(stack_inf->ope_inf);
	// end_program(stack_inf);
}

int	push_swap(t_stack_inf *stack_inf)
{
	int	lst_size;

	lst_size = stack_inf->arry_len;
	if (1 < lst_size && lst_size <= 3)
		basic_sort(stack_inf, A_TOP, lst_size);
	else if (3 < lst_size)
		split_chunk(stack_inf, A_TOP, lst_size / 3, lst_size);
	else
		throw_err(stack_inf, NULL, MEM_ALLOC_ERR);
	return (0);
}

void	split_chunk(t_stack_inf *stack_inf, int pos, int index, int unit_num)
{
	int	sec_index;
	int	n_unum;
	int	a_position;

	if (unit_num <= 3)
	{
		basic_sort(stack_inf, pos, unit_num);
		return ;
	}
	split_operation(stack_inf, pos, index, unit_num);
	sec_index = index + unit_num / 3;
	n_unum = unit_num / 3;
	a_position = A_BOTTOM;
	if (ft_lstsize(stack_inf->stack_a) <= n_unum + unit_num % 3)
		a_position = A_TOP;
	split_chunk(stack_inf, a_position, sec_index + n_unum / 3, n_unum 
	+ unit_num % 3);
	split_chunk(stack_inf, B_TOP, index + n_unum / 3, n_unum);
	split_chunk(stack_inf, B_BOTTOM, index - (n_unum - n_unum / 3), n_unum);
}

void	split_operation(t_stack_inf *stack_inf, int pos, int index, int u_num)
{
	int	i;
	int	j;
	int	target_num;

	if (!stack_inf)
		throw_err(stack_inf, NULL, NULL_ERR);
	i = 0;
	j = 0;
	while (i < u_num)
	{
		target_num = take_first_elem(stack_inf, pos);
		if (target_num < stack_inf->sorted_arry[index])
			move_to_b_bottom(stack_inf, pos);
		else if (stack_inf->sorted_arry[index + u_num / 3] <= target_num)
			move_to_a_bottom(stack_inf, pos);
		else
			move_to_b_top(stack_inf, pos);
		if (pos != A_TOP && take_first_elem(stack_inf, pos) == target_num)
		{
			move_to_a_top(stack_inf, pos);
			j++;
		}
		i++;
	}
	move_back(stack_inf, pos, j);
}
