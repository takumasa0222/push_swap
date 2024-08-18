/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:44:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/18 20:59:45 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int argc, char *argv[])
{
	void *init_data;// this data should be 

	validate_args(argc, argv);
	push_swap(argv);
	return (0);
}

push_swap(char **argv)
{
	int		arg_size;
	int		arry[500];
	t_list	stack_a;
	t_list	stack_b;
	
	arg_size = 0;
 	transform_arg_to_arry(argv, &arry, sizeof(arry)/sizeof(int), &arg_size);
	create_index(&arry, arg_size);
	sort_operation();
}
