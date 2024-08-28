/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:08:36 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/29 04:58:15 by tamatsuu         ###   ########.fr       */
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

void	init_stack(t_stack_inf *stack_inf, int *int_arry, int len)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = ft_lstnew(&int_arry[i]);
	if (!temp)
		return (free(int_arry), throw_err(stack_inf, NULL, MEM_ALLOC_ERR));
	stack_inf->stack_a = temp;
	i++;
	while (i < len)
	{
		temp = ft_lstnew(&int_arry[i]);
		if (!temp)
			return (free(int_arry), throw_err(stack_inf, NULL, MEM_ALLOC_ERR));
		ft_lstadd_back(&stack_inf->stack_a, temp);
		i++;
	}
	stack_inf->stack_b = NULL;
}

void	create_index(int **int_arry, int len, t_stack_inf *stack_inf)
{
	int	i;
	int	tmp;

	if (1 < len)
		quick_sort(*int_arry, 0, len - 1);
	i = 0;
	tmp = (*int_arry)[i];
	i++;
	while (i < len)
	{
		if (tmp == (*int_arry)[i])
		{
			free(*int_arry);
			throw_err(stack_inf, NULL, INVALID_ARG_ERR);
		}
		tmp = (*int_arry)[i];
		i++;
	}
}

int	partition(int *arr, int low, int high)
{
	int	piv;
	int	l_mrk;
	int	r_mrk;

	piv = low;
	l_mrk = low + 1;
	r_mrk = high;
	if (l_mrk == r_mrk && arr[piv] < arr[r_mrk])
		return (r_mrk);
	while (l_mrk < r_mrk)
	{
		while (l_mrk <= r_mrk && arr[l_mrk] <= arr[piv])
			l_mrk++;
		while (l_mrk <= r_mrk && arr[piv] <= arr[r_mrk])
			r_mrk--;
		if (l_mrk < r_mrk)
			swap(&arr[l_mrk], &arr[r_mrk]);
	}
	swap(&arr[piv], &arr[r_mrk]);
	return (r_mrk);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
