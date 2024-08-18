/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:44:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/17 02:53:30 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int argc, char *argv[])
{
	void *init_data;

	validate_args(argc, argv);
	init_data = transform_data(argv);
	push_swap(&init_data);
	return (0);
}

push_swap(void *init_data)
{
	
}
