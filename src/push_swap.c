/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:16:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/20 05:16:40 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	init(char **argv)
{
	int			arg_size;
	int			arry[ARRY_SIZE];
	int			op_arry[10000];
	t_stack_inf	*stack_inf;
	t_ope_inf	*op_inf;

	arg_size = 0;
	stack_inf = malloc(1 * sizeof(t_stack_inf));
	op_inf = malloc(1 * sizeof(t_ope_inf));
	if (!stack_inf || !op_inf)
		throw_err(stack_inf, op_inf, MEM_ALLOCATION_ERR);
	op_inf->i = 0;
	stack_inf->stack_a = ft_lstnew(NULL);
	stack_inf->stack_b = ft_lstnew(NULL);
	if (!stack_inf->stack_a || !stack_inf->stack_b)
		throw_err(stack_inf, op_inf, MEM_ALLOCATION_ERR);
	tsfrm_arg_to_arry(argv, &arry, ARRY_SIZE, &arg_size);
	//push array value into stack_a
	init_stack(stack_inf->stack_a, arry, arg_size);
	//sort arry and create index
	create_index(&arry, arg_size);
	stack_inf->sorted_arry = arry;
	stack_inf->ope_inf->op_arry = op_arry;
	push_swap(stack_inf);
}

int	push_swap(t_stack_inf *stack_inf)
{
	int	lst_size;

	lst_size = ft_lstsize(stack_inf->stack_a);
	if (1 < lst_size && lst_size <= 5)
		basic_sort(stack_inf, A_BOTTOM, lst_size);
	else if (5 < lst_size)
		split_chunk(stack_inf, A_BOTTOM, lst_size / 3, lst_size);
	else
		throw_err(stack_inf, NULL, MEM_ALLOCATION_ERR);
}

void	split_chunk(t_stack_inf *stack_inf, int pos, int index, int unit_num)
{
	if (base_case())
	{
		basic_sort(stack_inf, pos, unit_num);
		return ;
	}
	// split_operation(stack_a,stack_b, );
	split_chunk(stack_inf, A_BOTTOM, unit_num / 3 * 2 + unit_num / 9, unit_num / 3);
	split_chunk(stack_inf, B_TOP, unit_num / 3 + unit_num / 9, unit_num / 3);
	split_chunk(stack_inf, B_BOTTOM, unit_num + unit_num / 9, unit_num / 3);
}
// 	split_operation()
// {

// }
int	basic_sort(t_stack_inf *stack_inf, int pos, int unit_num)
{
	if (1 < unit_num && unit_num <= 5)
		short_sort();
	else if (3 < unit_num && unit_num <= 5)
		mid_sort(stack_inf, A_BOTTOM);
	else
		throw_err(stack_inf, NULL, MEM_ALLOCATION_ERR);
}