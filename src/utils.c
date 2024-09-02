/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:16:38 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/02 01:24:19 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

void	throw_err(t_stack_inf *stack_inf, t_ope_inf *ope_inf, int err_code)
{
	free_stack_inf(stack_inf);
	free(ope_inf);
	write_err(err_code);
	exit(0);
}

void	free_stack_inf(t_stack_inf *stack_inf)
{
	if (!stack_inf)
		return ;
	ft_lstclear(&stack_inf->stack_a, &delete);
	stack_inf->stack_a = NULL;
	ft_lstclear(&stack_inf->stack_b, &delete);
	stack_inf->stack_b = NULL;
	free(stack_inf->sorted_arry);
	stack_inf->sorted_arry = NULL;
	free(stack_inf->ope_inf);
	stack_inf->ope_inf = NULL;
	free(stack_inf->original_arry);
	free(stack_inf);
}

void	delete(void *val)
{
	(void)val;
	return ;
}

int	write_err(int err_code)
{
	ft_putstr_fd(ERR_MSG, STDOUT_FILENO);
	return (err_code);
}

void	throw_validation_err(char **str_arry, int *int_arry, int err_code)
{
	free_arry(&str_arry);
	free(int_arry);
	write_err(err_code);
	exit(0);
}
