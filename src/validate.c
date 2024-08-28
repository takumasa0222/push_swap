/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:53:27 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/29 00:48:38 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "push_swap.h"
#include <limits.h>

void	validate_args(int argc, char **argv, int **int_arry, int *len)
{
	char	**arg_arry;

	number_of_arg_check(argc);
	trsform_arg(argc, argv, &arg_arry);
	init_int_arry(arg_arry, int_arry);
	int_check_and_assign(arg_arry, int_arry);
	*len = arry_size(arg_arry);
	free_arry(&arg_arry);
}

void	number_of_arg_check(int argc)
{
	if (argc == 1)
		exit(0);
}

int	trsform_arg(int argc, char **argv, char ***arg_arry)
{
	int		i;
	char	**temp;
	int		cnt;
	int		j;
	int		k;

	i = 0;
	k = 0;
	temp = NULL;
	cnt = arg_size(argc, argv, *arg_arry);
	*arg_arry = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!*arg_arry)
		throw_validation_err(NULL, NULL, MEM_ALLOC_ERR);
	while (i < argc - 1 && k < cnt)
	{	
		temp = ft_split(argv[i++ + 1], ' ');
		if (!temp)
			throw_validation_err(*arg_arry, NULL, MEM_ALLOC_ERR);
		j = 0;
		while (j < arry_size(temp))
			(*arg_arry)[k++] = temp[j++];
		free(temp);
		temp = NULL;
	}
	return ((*arg_arry)[k] = NULL, 0);
}

int	int_check_and_assign(char **arry, int **int_arry)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = 0;
	if (!arry || !int_arry)
		throw_validation_err(arry, *int_arry, MEM_ALLOC_ERR);
	while (arry[i])
	{
		if (ft_strlen(arry[i]) > INT_MIN_LEN || !digit_check(arry[i]))
			throw_validation_err(arry, *int_arry, INVALID_ARG_ERR);
		tmp = (ft_atol(arry[i]));
		if (tmp < INT_MIN || INT_MAX < tmp)
			throw_validation_err(arry, *int_arry, INVALID_ARG_ERR);
		(*int_arry)[i] = (int)tmp;
		i++;
	}
	return (0);
}

int	init_int_arry(char **char_arry, int **int_arry)
{
	int	arry_len;

	if (!char_arry || !int_arry)
		throw_validation_err(char_arry, *int_arry, MEM_ALLOC_ERR);
	arry_len = arry_size(char_arry);
	*int_arry = (int *)malloc((arry_len) * sizeof(int));
	if (!*int_arry)
		throw_validation_err(char_arry, NULL, MEM_ALLOC_ERR);
	return (0);
}
