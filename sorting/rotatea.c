/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:14:42 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 15:02:19 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotatea(t_s *stacks)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = ft_atoi(stacks->a[0]);
	while (stacks->a[j])
	{
		if (ft_atoi(stacks->a[j]) > k)
		{
			i = j;
			k = ft_atoi(stacks->a[j]);
		}
		j++;
	}
	if ((size(stacks->a) - i + 1) < i)
	{
		while ((ft_atoi(stacks->a[j - 1]) != k))
			flags(stacks, RR, A);
	}
	else
		while (ft_atol(stacks->a[j - 1]) != k)
			flags(stacks, R, A);
}

void	rotateb(t_s *stacks)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = ft_atoi(stacks->b[0]);
	while (j < size(stacks->b))
	{
		if (k < ft_atoi(stacks->b[j]))
		{
			i = j;
			k = ft_atoi(stacks->b[j]);
		}
		j++;
	}
	if ((size(stacks->a) - i + 1) < i)
		while (ft_atoi(stacks->b[0]) != k)
			flags(stacks, RR, B);
	else
		while (ft_atoi(stacks->b[0]) != k)
			flags(stacks, R, B);
}
