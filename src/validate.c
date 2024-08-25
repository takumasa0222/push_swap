/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:53:27 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/25 23:34:49 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	validate_args(int argc, char **argv)
{
	char	**arg_arry;
	int		**int_arry;

	number_of_arg_check(argc);
	trsform_arg(argc, argv, &arg_arry);
	arg_integer_check(arg_arry, &int_arry);
	//arg_dup_check();
}

void	number_of_arg_check(int argc)
{
	if (argc == 1)
		exit(0);
}

void	trsform_arg(int argc, char **argv, char ***arg_arry)
{
	int		i;
	char	**temp;
	int		cnt;
	int		j;
	int		k;

	i = 0;
	k = 0;
	temp = NULL;
	cnt = arg_size(argc, argv);
	*arg_arry = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!*arg_arry)
		throw_err(NULL, NULL, MEM_ALLOCATION_ERR);
	while (i < argc - 1 && k <cnt)
	{	
		temp = ft_split(argv[i++ + 1], ' ');
		if (!temp)
			throw_err(NULL, NULL, MEM_ALLOCATION_ERR);
		j = 0;
		while (j < arry_size(temp))
			(*arg_arry)[k++] = temp[j++];
		free(temp);
		temp = NULL;
	}
	(*arg_arry)[k] = NULL;
}


int	arg_size(int argc, char **argv)
{
	int		i;
	int		ret;
	char	**temp;

	i = 0;
	ret = 0;
	temp = NULL;
	while (i < argc - 1)
	{
		temp = ft_split(argv[i + 1], ' ');
		if (!temp)
			throw_err(NULL, NULL, MEM_ALLOCATION_ERR);
		ret = ret + arry_size(temp);
		free_arry(&temp);
		i++;
	}
	return (ret);
}

void	free_arry(char ***arry)
{
	int	i;

	i = 0;
	if (!arry && !*arry)
		return ;
	while ((*arry)[i])
	{	
		free((*arry)[i]);
		(*arry)[i] = NULL;
		i++;
	}
	free(*arry);
	*arry = NULL;
}

int	arry_size(char **arry)
{
	int	i;

	i = 0;
	if (!arry)
		return (i);
	while (arry[i])
		i++;
	return (i);
}

void	arg_integer_check(int argc, char **argv)
{
	int	i;
	i = 0;
	while (i < argc - 1)
	{
		if(ft_isdigit(ft_atoi(argv[i]))
	}
}
