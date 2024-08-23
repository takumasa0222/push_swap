/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:16:38 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/24 04:01:46 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

void	throw_err(t_stack_inf *stack_inf, t_ope_inf *ope_inf, int err_code)
{
	int	err_no;

	err_no = 0;
	free_stack_inf(stack_inf);
	free(ope_inf);
	err_no = write_err(err_code);
	exit(err_no);
}

void	free_stack_inf(t_stack_inf *stack_inf)
{
	if (!stack_inf)
		return ;
	ft_lstclear(stack_inf->stack_a, &delete);
	stack_inf->stack_a = NULL;
	ft_lstclear(stack_inf->stack_b, &delete);
	stack_inf->stack_b = NULL;
	stack_inf->sorted_arry = NULL;
	free(stack_inf->ope_inf);
	stack_inf->ope_inf = NULL;
	free(stack_inf);
}

void	delete(void *val)
{
	val = NULL;
	return ;
}

int	write_err(int err_code)
{
	ft_putstr_fd(ERR_MSG, stdout);
	return (0);
}
