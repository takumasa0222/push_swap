/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 00:07:21 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/24 02:27:54 by tamatsuu         ###   ########.fr       */
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


//describe_ope(t_ope_inf ope_inf, enum e_push_swap_code op)
//{
	
//}