/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:03:12 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/09/01 18:33:23 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	arg_size(int argc, char **argv, char **arg_arry)
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
			throw_validation_err(arg_arry, NULL, MEM_ALLOC_ERR);
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

int	digit_check(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && (str[0] == '-' || str[0] == '+'))
		return (0);
	return (1);
}

long	ft_atol(char *str)
{
	int		minus_flag;
	long	result;

	minus_flag = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' \
	|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_flag = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		result = result * 10 + (long)(*str - 48);
		str++;
	}
	return ((minus_flag * result));
}
