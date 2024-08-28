/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:51:48 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/29 04:35:18 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ARRY_SIZE 500
# define A_BOTTOM 0
# define B_TOP 1
# define B_BOTTOM 2
# define A_TOP 3

# define MEM_ALLOC_ERR -1
# define ARG_NULL_ERR -2
# define NULL_ERR -3
# define INVALID_ARG_ERR -4

# define SA_W "SA"
# define PA_W "PA"
# define RA_W "RA"
# define RRA_W "RRA"
# define SB_W "SB"
# define PB_W "PB"
# define RB_W "RB"
# define RRB_W "RRB"

# define ERR_NO 99
# define INT_MIN_LEN 11

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
	int			arry_len;
}	t_stack_inf;

// validate.c
void	validate_args(int argc, char **argv, int **int_arry, int *len);
void	number_of_arg_check(int argc);
int		trsform_arg(int argc, char **argv, char ***arg_arry);
int		int_check_and_assign(char **arry, int **int_arry);
int		init_int_arry(char **char_arry, int **int_arry);
// validation_utils.c
int		arg_size(int argc, char **argv, char **arg_arry);
void	free_arry(char ***arry);
int		arry_size(char **arry);
int		digit_check(char *str);
long	ft_atol(char *str);
// utils.c
void	throw_validation_err(char **str_arry, int *int_arry, int err_code);
void	throw_err(t_stack_inf *stack_inf, t_ope_inf *ope_inf, int err_code);
void	free_stack_inf(t_stack_inf *stack_inf);
void	delete(void *val);
int		write_err(int err_code);
// push_swap.c
void	init(int **int_arry, int len);
int		push_swap(t_stack_inf *stack_inf);
void	split_chunk(t_stack_inf *stack_inf, int pos, int index, int unit_num);
void	split_operation(t_stack_inf *stack_inf, int pos, int index, int u_num);

// push_swap_utils.c
int		take_first_elem(t_stack_inf *stack_inf, int pos);
void	init_stack(t_stack_inf *stack_inf, int *int_arry, int len);
void	create_index(int **int_arry, int len, t_stack_inf *stack_inf);
int		partition(int *arr, int low, int high);
void	quick_sort(int *arr, int low, int high);
// push_swap_utils_2.c
void	swap(int *a, int *b);
// move.c
void	move_to_a_top(t_stack_inf *stack_inf, int pos);
void	move_to_a_bottom(t_stack_inf *stack_inf, int pos);
void	move_to_b_top(t_stack_inf *stack_inf, int pos);
void	move_to_b_bottom(t_stack_inf *stack_inf, int pos);
void	move_back(t_stack_inf *stack_inf, int pos, int j);
// ope_info_utils.c
void	add_ope(t_ope_inf *ope_inf, enum e_push_swap_code cd);
// sort.c
void	basic_sort(t_stack_inf *stack_inf, int pos, int unit_num);
void	super_short_sort(t_stack_inf *stack_inf);
int		tp(t_list *stack, int i);
void	sort_two(t_stack_inf *stack_inf);
void	short_sort(t_stack_inf *stack_inf);

//stack_a_operation.c
void	sa(t_stack_inf *stack_inf);
void	pa(t_stack_inf *stack_inf);
void	ra(t_stack_inf *stack_inf);
void	rra(t_stack_inf *stack_inf);

//stack_b_operation.c
void	sb(t_stack_inf *stack_inf);
void	pb(t_stack_inf *stack_inf);
void	rb(t_stack_inf *stack_inf);
void	rrb(t_stack_inf *stack_inf);
// listutils.c
void	ft_lstswap_front(t_list **lst);
void	describe_ope(t_ope_inf *ope_inf);

#endif