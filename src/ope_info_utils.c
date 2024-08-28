/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:07:21 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/29 04:36:33 by tamatsuu         ###   ########.fr       */
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
		i++;
	}
}

// void	optimize_ope(t_ope_inf *ope_inf)
// {

// }
