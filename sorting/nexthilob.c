/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nexthilob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:19:29 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/16 18:02:44 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nlnb(t_s *stacks, int i)
{
	int	low;
	int	j;

	j = 0;
	low = 0;
	while (j <= size(stacks->b))
	{
		if (ft_atoi(stacks->b[low]) < ft_atoi(stacks->b[j])
			&& ft_atoi(stacks->b[j]) < ft_atoi(stacks->a[i]))
			low = j;
		++j;
	}
	if (ft_atoi(stacks->b[low]) > ft_atoi(stacks->a[i]))
		return (-1);
	else
		return (low);
}

int	nhnb(t_s *stacks, int i)
{
	int	hi;
	int	j;

	hi = 0;
	j = 1;
	while (j <= size(stacks->b))
	{
		if (ft_atoi(stacks->b[hi]) < ft_atoi(stacks->b[j]))
			hi = j;
		++j;
	}
	j = 0;
	while (j <= size(stacks->b))
	{
		if (ft_atoi(stacks->b[hi]) > ft_atoi(stacks->b[j])
			&& ft_atoi(stacks->b[j]) > ft_atoi(stacks->a[i]))
				hi = j;
		else if (ft_atoi(stacks->b[j]) == (ft_atoi(stacks->a[i]) + 1))
				hi = j;
		++j;
	}
	if (ft_atoi(stacks->b[hi]) < ft_atoi(stacks->a[i]))
		return (-1);
	else
		return (hi);
}

void	positionb(t_s *stacks, int i)
{
	int	k;
	int	j;

	k = (0 - nlnb(stacks, i)) * -1;
	j = size(stacks->b) - nlnb(stacks, i) + 1;
	if (i > j)
		stacks->speed = stacks->speed + j;
	else
		stacks->speed = stacks->speed + k;
}
