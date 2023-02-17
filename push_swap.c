/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:24:19 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 16:03:06 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortmed(t_s *stacks)
{
	flags(stacks, P, B);
	while (size(stacks->a) != 2)
	{
		operationsa(stacks);
		pushb(stacks);
		flags(stacks, P, B);
	}
	sort_small(stacks);
}

int	main(int argc, char *argv[])
{
	t_s	stacks;

	if (argc < 2)
		return (ft_printf("ERROR\n"));
	if (read_input(argc, argv, &stacks) != ERR_INVAL)
	{
		if (size(stacks.a) == 1)
			sort_two(&stacks);
		if (sorted(&stacks) == NO)
		{
			if (size(stacks.a) >= 3 && size(stacks.a) <= 4)
			{
				sortmed(&stacks);
				sort_back(&stacks);
			}
			else if (size(stacks.a) > 4)
				sort(&stacks, -1);
			else if (size(stacks.a) == 2)
				sort_small(&stacks);
		}
		while (size(stacks.b) != -1)
			flags(&stacks, P, A);
		rotatea(&stacks);
	}
	return (0);
}
