/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:48:31 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 16:02:57 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_s *stacks)
{
	int	i;
	int	j;

	i = size(stacks->a);
	while (i > 0 && (ft_atol(stacks->a[i]) > ft_atol(stacks->a[i - 1])))
		--i;
	j = size(stacks->b);
	while (i > 0 && (ft_atol(stacks->a[i]) > ft_atol(stacks->a[i - 1])))
		--j;
	if (i != 0 && j != 0)
		return (NO);
	else
		return (YES);
}
