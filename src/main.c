/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:44:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/29 01:38:36 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	*int_arry;
	int	arry_len;
	
	validate_args(argc, argv, &int_arry, &arry_len);
	for (int i = 0; i < arry_len; i++)
		printf("int : %d\n", int_arry[i]);
	init(&int_arry, arry_len);
	return (0);
}
