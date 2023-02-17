/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:53:52 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/16 18:14:39 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assignvaluesb(t_s *stacks)
{
	stacks->valo = 0;
	stacks->vahi = 0;
	if (nlnb(stacks, stacks->num) != -1)
		stacks->valo = ft_atoi(stacks->b[nlnb(stacks, stacks->num)]);
	if (nhnb(stacks, stacks->num) != -1)
		stacks->vahi = ft_atoi(stacks->b[nhnb(stacks, stacks->num)]);
}

void	rotatestackb(t_s *stacks)
{
	assignvaluesb(stacks);
	if (nlnb(stacks, stacks->num) != -1)
	{
		if ((size(stacks->b) - nlnb(stacks, stacks->num) + 1)
			> nlnb(stacks, stacks->num))
			while (ft_atoi(stacks->b[0]) != stacks->valo)
				flags(stacks, R, B);
		else
			while (ft_atoi(stacks->b[0]) != stacks->valo)
				flags(stacks, RR, B);
	}
	else
	{
		if ((size(stacks->b) - nhnb(stacks, stacks->num))
			> nhnb(stacks, stacks->num) + 1)
			while (ft_atoi(stacks->b[size(stacks->b)]) != stacks->vahi)
				flags(stacks, R, B);
		else
			while (ft_atoi(stacks->b[size(stacks->b)]) != stacks->vahi)
				flags(stacks, RR, B);
	}
}

void	rotatestacka(t_s *stacks)
{
	int	top;
	int	bot;
	int	val;

	top = stacks->num;
	bot = (size(stacks->a) - stacks->num + 1);
	val = ft_atoi(stacks->a[stacks->num]);
	if (top < bot)
		while (ft_atoi(stacks->a[0]) != val)
			flags(stacks, R, A);
	else
		while (ft_atoi(stacks->a[0]) != val)
			flags(stacks, RR, A);
}

void	pushb(t_s *stacks)
{
	rotatestackb(stacks);
	rotatestacka(stacks);
}
