/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 02:53:27 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/17 03:01:04 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

validate_args(int argc, char *argv[])
{
	number_of_arg_check(argc);
	arg_integer_check(argv);
	arg_dup_check();
}

