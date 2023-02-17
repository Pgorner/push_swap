/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:16:18 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/15 20:01:09 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cases(t_s *stacks, int i)
{
	if (i == 1)
		flags(stacks, S, A);
	if (i == 2)
	{
		flags(stacks, S, A);
		flags(stacks, RR, A);
	}
	if (i == 3)
		flags(stacks, R, A);
	if (i == 4)
	{
		flags(stacks, S, A);
		flags(stacks, R, A);
	}
	if (i == 5)
		flags(stacks, RR, A);
}

void	sort_small(t_s *stacks)
{
	if (ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[0]) < ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[1]) < ft_atoi(stacks->a[2]))
		cases(stacks, 1);
	else if (ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[1]) > ft_atoi(stacks->a[2]))
		cases(stacks, 2);
	else if (ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[1]) < ft_atoi(stacks->a[2]))
		cases(stacks, 3);
	else if (ft_atoi(stacks->a[0]) < ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[0]) < ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[1]) > ft_atoi(stacks->a[2]))
		cases(stacks, 4);
	else if (ft_atoi(stacks->a[0]) < ft_atoi(stacks->a[1])
		&& ft_atoi(stacks->a[0]) > ft_atoi(stacks->a[2])
		&& ft_atoi(stacks->a[1]) > ft_atoi(stacks->a[2]))
		cases(stacks, 5);
}
