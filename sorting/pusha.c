/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:53:52 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 13:09:11 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assignvaluesa(t_s *stacks)
{
	stacks->valo = 0;
	stacks->vahi = 0;
	if (nlna(stacks, stacks->num) != -1)
		stacks->valo = ft_atoi(stacks->a[nlna(stacks, stacks->num)]);
	if (nhna(stacks, stacks->num) != -1)
		stacks->vahi = ft_atoi(stacks->a[nhna(stacks, stacks->num)]);
}

void	rotstacka(t_s *stacks)
{
	assignvaluesa(stacks);
	if (nlna(stacks, stacks->num) != -1)
	{
		if ((size(stacks->a) - nlna(stacks, stacks->num) + 1)
			> nlna(stacks, stacks->num))
			while (ft_atoi(stacks->a[size(stacks->a)]) != stacks->valo)
				flags(stacks, R, A);
		else
			while (ft_atoi(stacks->a[size(stacks->a)]) != stacks->valo)
				flags(stacks, RR, A);
	}
	else
	{
		if ((size(stacks->a) - nhna(stacks, stacks->num))
			> nhna(stacks, stacks->num) + 1)
			while (ft_atoi(stacks->a[0]) != stacks->vahi)
				flags(stacks, R, A);
		else
			while (ft_atoi(stacks->a[0]) != stacks->vahi)
				flags(stacks, RR, A);
	}
}

void	rotstackb(t_s *stacks)
{
	int	top;
	int	bot;
	int	val;

	top = stacks->num;
	bot = (size(stacks->b) - stacks->num + 1);
	val = ft_atoi(stacks->b[stacks->num]);
	if (top < bot)
		while (ft_atoi(stacks->b[0]) != val)
			flags(stacks, R, B);
	else
		while (ft_atoi(stacks->b[0]) != val)
			flags(stacks, RR, B);
}

void	pusha(t_s *stacks)
{
	rotstacka(stacks);
	rotstackb(stacks);
}
