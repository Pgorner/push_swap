/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:54:05 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 15:32:45 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_s *stacks)
{
	flags(stacks, S, A);
}

void	sort(t_s *stacks, int i)
{
	if (size(stacks->a) > 2)
	{
		flags(stacks, P, B);
		flags(stacks, P, B);
	}
	else
		flags(stacks, P, B);
	while (size(stacks->a) != i)
	{
		operationsa(stacks);
		pushb(stacks);
		flags(stacks, P, B);
	}
}

void	sort_back(t_s *stacks)
{
	while (size(stacks->b) != -1)
	{
		operationsb(stacks);
		pusha(stacks);
		flags(stacks, P, A);
	}
}
