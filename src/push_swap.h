/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:51:48 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/25 21:49:13 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
# define ARRY_SIZE 500
# define A_BOTTOM 0
# define B_TOP 1
# define B_BOTTOM 2
# define A_TOP 3

# define MEM_ALLOCATION_ERR -1
# define ARG_NULL_ERR -2
# define NULL_ERR -3

# define ERR_MSG "ERROR\n"

enum e_push_swap_code
{
	SA,
	PA,
	RA,
	RRA,
	SB,
	PB,
	RB,
	RRB,
	RR,
	RRR
};

typedef struct s_ope_inf
{
	int		*op_arry;
	int		i;
}	t_ope_inf;

typedef struct s_stack_inf
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_ope_inf	*ope_inf;
	int			*sorted_arry;
}	t_stack_inf;

void	validate_args(int argc, char **argv);
void	number_of_arg_check(int argc);
void	trsform_arg(int argc, char **argv, char ***arg_arry);
int		arg_size(int argc, char **argv);
void	free_arry(char ***arry);
int		arry_size(char **arry);

void	throw_err(t_stack_inf *stack_inf, t_ope_inf *ope_inf, int err_code);
void	free_stack_inf(t_stack_inf *stack_inf);
void	delete(void *val);
int		write_err(int err_code);

#endif