/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:44:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/18 23:47:31 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	validate_args(argc, argv);
	init(argv);
	return (0);
}

int	init(char **argv)
{
	int		arg_size;
	int		arry[ARRY_SIZE];
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*op_list;

	arg_size = 0;
	stack_a = ft_lstnew(NULL);
	stack_b = ft_lstnew(NULL);
	op_list = ft_lstnew(NULL);
	if (!stack_a || !stack_b)
		throw_err(MEM_ALLOCATION_ERR);
	tsfrm_arg_to_arry(argv, &arry, ARRY_SIZE, &arg_size);
	init_stack(stack_a, arry, arg_size); //push array value into stack_a
	create_index(&arry, arg_size); //sort arry and create index
	push_swap(stack_a, stack_b, op_list, arry);
}

int	push_swap(t_list *stack_a, t_list *stack_b, t_list *op_lst, int *arry)
{
	int	lst_size;

	lst_size = ft_lstsize(stack_a);
}

void	split_chunk(t_list *stack_a, t_list *stack_b, int mid_val, t_split_info *meta)
{
	if (base_case())
	{
		basic_sort(stack_a, stack_b);
		return ;
	}
	split_operation(stack_a,stack_b, meta);
	split_chunk(stack_a,stack_b, meta);
	split_chunk(stack_a,stack_b, meta);
	split_chunk(stack_a,stack_b, meta);
}
