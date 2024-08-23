/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:08:36 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/24 04:14:14 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	take_first_elem(t_stack_inf *stack_inf, int pos)
{
	t_list	*last_lst;

	last_lst = NULL;
	if (pos == A_TOP)
		return (*(int *)stack_inf->stack_a->content);
	else if (pos == A_BOTTOM)
	{
		last_lst = ft_lstlast(stack_inf->stack_a);
		return (*(int *)last_lst->content);
	}
	else if (pos == B_TOP)
		return (*(int *)stack_inf->stack_b->content);
	else
	{
		last_lst = ft_lstlast(stack_inf->stack_b);
		return (*(int *)last_lst->content);
	}
}
