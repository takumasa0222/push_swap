/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:05:32 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/20 14:06:21 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "src/push_swap.h"
#include "libft/libft.h"

void delete(void *test)
{
	test = NULL;
	return ;	
}

int	main(void)
{
	t_ope_inf *op_inf;
	t_stack_inf *stack_inf;
	int a, b, c, d, e;
	t_list	*temp_a, *temp_b;
	//exit(0);

	a = 1;
	b = 3;
	c = 5;
	d = 7;
	e = 9;
	stack_inf = malloc(1 * sizeof(t_stack_inf));
	op_inf = malloc(1 * sizeof(t_ope_inf));
	//if (!stack_inf || !op_inf)
	//	throw_err(stack_inf, op_inf, MEM_ALLOCATION_ERR);
	op_inf->i = 0;
	stack_inf->stack_a = ft_lstnew(&a);
	stack_inf->stack_a->next = ft_lstnew(&b);
	stack_inf->stack_a->next->next = ft_lstnew(&c);
	stack_inf->stack_a->next->next->next = ft_lstnew(&d);
	stack_inf->stack_b = ft_lstnew(NULL);
	temp_a = stack_inf->stack_a; 
	while (temp_a)
	{
		printf("value is %d\n",*((int*)temp_a->content));
		temp_a = temp_a->next;
	}
	sa(stack_inf);
	temp_a = stack_inf->stack_a; 
	printf("after sa\n");
	while (temp_a)
	{
		printf("value is %d\n",*((int*)temp_a->content));
		temp_a = temp_a->next;
	}

	ra(stack_inf);
	temp_a = stack_inf->stack_a; 
	printf("after ra\n");
	while (temp_a)
	{
		printf("value is %d\n",*((int*)temp_a->content));
		temp_a = temp_a->next;
	}
	printf("after rra\n");
	rra(stack_inf);
	temp_a = stack_inf->stack_a; 
	while (temp_a)
	{
		printf("value is %d\n",*((int*)temp_a->content));
		temp_a = temp_a->next;
	}
	printf("after pa\n");
	pa(stack_inf);
	temp_a = stack_inf->stack_a; 
	while (temp_a)
	{
		if (!temp_a->content)
			break ;
		printf("value is %d\n",*((int*)temp_a->content));
		temp_a = temp_a->next;
	}
	pa(stack_inf);
	printf("pb status %p\n",stack_inf->stack_b);
	ft_lstclear(&stack_inf->stack_a, &delete);
	free(op_inf);
	free(stack_inf);
}

