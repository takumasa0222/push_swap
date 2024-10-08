/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:44:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/01 16:44:17 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*int_arry;
	int	arry_len;

	validate_args(argc, argv, &int_arry, &arry_len);
	init(&int_arry, arry_len);
	return (0);
}
