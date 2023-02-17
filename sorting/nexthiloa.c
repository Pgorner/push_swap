/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexthiloa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:19:29 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/16 18:00:37 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nlna(t_s *stacks, int i)
{
	int	low;
	int	j;

	j = 0;
	low = 0;
	while (j <= size(stacks->a))
	{
		if (ft_atoi(stacks->a[low]) < ft_atoi(stacks->a[j])
			&& ft_atoi(stacks->a[j]) < ft_atoi(stacks->b[i]))
			low = j;
		++j;
	}
	if (ft_atoi(stacks->a[low]) > ft_atoi(stacks->b[i]))
		return (-1);
	else
		return (low);
}

int	nhna(t_s *stacks, int i)
{
	int	hi;
	int	j;

	hi = 0;
	j = 0;
	while (j <= size(stacks->a))
	{
		if (ft_atoi(stacks->a[hi]) < ft_atoi(stacks->a[j]))
			hi = j;
		++j;
	}
	j = 0;
	while (j <= size(stacks->a))
	{
		if (ft_atoi(stacks->a[hi]) > ft_atoi(stacks->a[j])
			&& ft_atoi(stacks->a[j]) > ft_atoi(stacks->b[i]))
				hi = j;
		++j;
	}
	if (ft_atoi(stacks->a[hi]) < ft_atoi(stacks->b[i]))
		return (-1);
	else
		return (hi);
}

void	positiona(t_s *stacks, int i)
{
	int	k;
	int	j;

	k = (0 - nlna(stacks, i)) * -1;
	j = size(stacks->a) - nlna(stacks, i) + 1;
	if (i > j)
		stacks->speed = stacks->speed + j;
	else
		stacks->speed = stacks->speed + k;
}
