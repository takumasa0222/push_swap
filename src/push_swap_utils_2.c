/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:17:13 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/31 20:57:32 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*copy_arry(int *int_arry, int len, t_stack_inf *stack_inf)
{
	int	*ret;
	int	i;

	ret = malloc(len * sizeof(int *));
	if (!ret)
		return (throw_err(stack_inf, NULL, MEM_ALLOC_ERR), NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = int_arry[i];
		i++;
	}
	return (ret);
}
#include <stdio.h>
int	is_arry_sorted(t_stack_inf *s_inf, int pos, int unum)
{
	int	i;
	int	tmp;

	i = 0;
	if (pos == A_TOP || pos == A_BOTTOM)
	{
		while (i < unum - 1)
		{
			tmp = take_x_elem(s_inf, pos, i);
			if (tmp > take_x_elem(s_inf, pos, i + 1))
				return (NOT_SORTED);
			i++;
		}
	}
	// else
	// {
	// 	while (i < unum - 1)
	// 	{
	// 		tmp = take_x_elem(s_inf->stack_b./, pos, i);
	// 		if (tmp < take_x_elem(s_inf->stack_b, pos, i + 1))
	// 			return (NOT_SORTED);
	// 		i++;
	// 	}
	// }
	return (SORTED);
}

int	take_x_elem(t_stack_inf *s_inf, int pos, int i)
{
	int		j;
	t_list	*temp;

	if (pos == A_TOP || pos == A_BOTTOM)
		temp = s_inf->stack_a;
	else
		temp = s_inf->stack_b;
	j = 0;
	if (pos == A_TOP || pos == B_TOP)
	{
		while (j++ < i)
			temp = temp->next;
	}
	else
	{
		// この機能が本当に比べたい値が取れているかは確認必要
		i = ft_lstsize(temp) - i - 1;
		while (j++ < i)
			temp = temp->next;
	}
	return (*(int *)temp->content);
}
