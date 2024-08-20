/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:17:54 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/20 14:10:06 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	sb(t_stack_inf *stack_inf)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_b) < 2)
		return ;
	ft_lstswap_front(&stack_inf->stack_b);
	describe_ope(stack_inf->ope_inf, SB);
}

void	pb(t_stack_inf *stack_inf)
{
	t_list	*tmp;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_a) == 0)
		return ;
	tmp = stack_inf->stack_a;
	stack_inf->stack_a = stack_inf->stack_a->next;
	tmp->next = stack_inf->stack_b;
	stack_inf->stack_b = tmp;
	describe_ope(stack_inf->ope_inf, PB);
}

void	rb(t_stack_inf *stack_inf)
{
	t_list	*tmp;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_b) < 2)
		return ;
	tmp = stack_inf->stack_b;
	stack_inf->stack_b = stack_inf->stack_b->next;
	tmp->next = NULL;
	ft_lstadd_back(&stack_inf->stack_b, tmp);
	describe_ope(stack_inf->ope_inf, RB);
}

void	rrb(t_stack_inf *stack_inf)
{
	t_list	*tmp;
	t_list	*second_last;

	if (!stack_inf)
		throw_err(stack_inf, NULL, ARG_NULL_ERR);
	if (ft_lstsize(stack_inf->stack_b) < 2)
		return ;
	tmp = ft_lstlast(stack_inf->stack_b);
	second_last = stack_inf->stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(&stack_inf->stack_b, tmp);
	describe_ope(stack_inf->ope_inf, RRB);
}
