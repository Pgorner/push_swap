/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:25:25 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 15:28:48 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid(int argc, char *argv[])
{
	if (check_digit(argc, argv) == ERR_INVAL
		|| space_check(argc, argv) == ERR_INVAL
		|| negpos_check(argc, argv) == ERR_INVAL)
		return (ERR_INVAL);
	else
		return (SUCESS);
}

int	read_input(int argc, char *argv[], t_s *stacks)
{
	if (ft_error(check_valid(argc, argv) == ERR_INVAL) == ERR_INVAL)
		return (ERR_INVAL);
	stacks->str = join_inpt(argc, argv);
	stacks->a = ft_split(stacks->str, SPACE);
	if (validsize(stacks) == ERR_INVAL)
		return (ERR_INVAL);
	if (check_double(stacks) == ERR_INVAL)
		return (ERR_INVAL);
	if (ft_error(check_double(stacks) == ERR_INVAL) == ERR_INVAL)
		return (ERR_INVAL);
	stacks->tmp = ft_calloc(sizeof(char), size(stacks->a));
	stacks->b = ft_calloc(sizeof(char), size(stacks->a));
	return (0);
}
