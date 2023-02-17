/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:20 by pgorner           #+#    #+#             */
/*   Updated: 2022/12/16 18:02:03 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	placeb(t_s *stacks, int i)
{
	int	hi;
	int	lo;
	int	o;

	hi = 0;
	lo = 0;
	o = i;
	while (o++ <= size(stacks->b))
		++lo;
	o = i;
	while (o-- > 0)
		++hi;
	if (hi > lo)
		stacks->speed = lo;
	else if (lo > hi)
		stacks->speed = hi;
	else if (lo == hi)
		stacks->speed = lo;
}

void	higha(t_s *stacks, int i)
{
	int	hi;
	int	lo;
	int	o;

	hi = 1;
	lo = 0;
	o = i;
	while (o++ <= size(stacks->a))
		++lo;
	o = i;
	while (o-- > 0)
		++hi;
	if (hi > lo)
		stacks->speed = stacks->speed + lo;
	else if (lo > hi)
		stacks->speed = stacks->speed + hi;
	else if (lo == hi)
		stacks->speed = stacks->speed + lo;
}

void	lowa(t_s *stacks, int i)
{
	int	hi;
	int	lo;
	int	o;

	hi = 0;
	lo = 0;
	o = i;
	while (o++ <= size(stacks->a))
		++lo;
	o = i;
	while (o-- > 0)
		++hi;
	if (hi > lo)
		stacks->speed = stacks->speed + lo;
	else if (lo > hi)
		stacks->speed = stacks->speed + hi;
	else if (lo == hi)
		stacks->speed = stacks->speed + lo;
}

void	placeina(t_s *stacks, int i)
{
	int	lo;
	int	hi;

	hi = 0;
	lo = 0;
	lo = nlna(stacks, i);
	hi = size(stacks->a) - nhna(stacks, i);
	if (((lo < hi && nlna(stacks, i) != -1)
			|| nhna(stacks, i) == -1)
		|| lo == hi)
		stacks->speed = stacks->speed + lo;
	if ((hi < lo && nhna(stacks, i) != -1)
		|| nlna(stacks, i) == -1)
		stacks->speed = stacks->speed + hi;
}

void	operationsb(t_s *stacks)
{
	int	i;

	stacks->num = 0;
	stacks->ispeed = INT_MAX;
	stacks->prevspeed = INT_MAX;
	i = 0;
	while (i <= size(stacks->b))
	{
		placea(stacks, i);
		placeina(stacks, i);
		if (stacks->speed < stacks->prevspeed
			&& stacks->speed < stacks->ispeed)
		{
			stacks->ispeed = stacks->speed;
			stacks->num = i;
		}
		stacks->prevspeed = stacks->speed;
		stacks->speed = 0;
		++i;
	}
}
