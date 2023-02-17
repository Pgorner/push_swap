/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:44:04 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 13:15:08 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validsize(t_s *stacks)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size(stacks->a))
	{
		if (ft_atol(stacks->a[i]) < INT_MIN
			|| ft_atol(stacks->a[i]) > INT_MAX)
			return (ERR_INVAL);
		j = 0;
		i++;
	}
	return (SUCESS);
}
