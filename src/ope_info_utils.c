/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:07:21 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/01 17:23:21 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	add_ope(t_ope_inf *ope_inf, enum e_push_swap_code cd)
{
	if (!ope_inf)
		return ;
	ope_inf->op_arry[ope_inf->i] = cd;
	ope_inf->i = ope_inf->i + 1;
}

void	describe_ope(t_ope_inf *ope_inf)
{
	int	i;

	i = 0;
	while (i < ope_inf->i)
	{
		if (ope_inf->op_arry[i] == SA)
			ft_putendl_fd(SA_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == PA)
			ft_putendl_fd(PA_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == RA)
			ft_putendl_fd(RA_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == RRA)
			ft_putendl_fd(RRA_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == SB)
			ft_putendl_fd(SB_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == PB)
			ft_putendl_fd(PB_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == RB)
			ft_putendl_fd(RB_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == RRB)
			ft_putendl_fd(RRB_W, STDOUT_FILENO);
		else if (ope_inf->op_arry[i] == RR)
			ft_putendl_fd(RR_W, STDOUT_FILENO);
		i++;
	}
}

void	optimize_ope(t_ope_inf *ope_inf)
{
	int	i;

	i = 0;
	while (i < ope_inf->i - 1)
	{
		if (ope_inf->op_arry[i] == RA && ope_inf->op_arry[i + 1] == RB)
		{
			ope_inf->op_arry[i] = RR;
			ope_inf->op_arry[i + 1] = UNDEFINED;
		}	
		else if (ope_inf->op_arry[i] == RB && ope_inf->op_arry[i + 1] == RA)
		{
			ope_inf->op_arry[i] = RR;
			ope_inf->op_arry[i + 1] = UNDEFINED;
		}
		i++;
	}
}
