/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:16:27 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 16:06:13 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_s *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size(stacks->a))
	{
		while (stacks->a[j + 1])
		{
			if (ft_atoi(stacks->a[i]) == ft_atoi(stacks->a[j]))
				if (i != j)
					return (ERR_INVAL);
			++j;
		}
		++i;
		j = i;
	}
	return (SUCESS);
}

int	is_digit(char check)
{
	if (check == '0' || check == '1' || check == '2'
		|| check == '3' || check == '4' || check == '5'
		|| check == '6' || check == '7' || check == '8'
		|| check == '9' || check == ' ' || check == '-' || check == '+' )
		return (SUCESS);
	else
		return (ERR_INVAL);
}

int	check_digit(int argc, char *argv[])
{
	int	i;
	int	j;
	int	s;

	j = 1;
	while (j < argc)
	{
		s = (ft_strlen(&argv[j][i]));
		i = 0;
		while (i <= s && argv[j][i] != '\0')
		{
			if (is_digit(argv[j][i]) == ERR_INVAL)
				return (ERR_INVAL);
			++i;
		}
		i = 0;
		++j;
	}
	return (SUCESS);
}

int	space_check(int argc, char *argv[])
{
	int	i;
	int	j;
	int	s;

	j = 1;
	while (j < argc)
	{
		s = (ft_strlen(&argv[j][i]) - 1);
		i = 0;
		if ((argv[j][0]) == '\0')
			return (ERR_INVAL);
		while (i <= s && argv[j][i] == SPACE)
		{
			if ((argv[j][i + 1]) == '\0')
				return (ERR_INVAL);
			++i;
		}
		i = 0;
		++j;
	}
	return (SUCESS);
}

int	negpos_check(int argc, char *argv[])
{
	int	i;
	int	j;
	int	s;

	j = 0;
	while (++j < argc)
	{
		i = 0;
		s = (ft_strlen(&argv[j][i]) - 1);
		while (i++ <= s)
		{
			if ((((argv[j][i]) == '+') || ((argv[j][i]) == '-'))
			&& (is_num(argv[j][i + 1]) == ERR_INVAL))
			{
				if (is_digit(argv[j][i - 1]) == SUCESS
				|| argv[j][i - 1] == '\0')
					return (ERR_INVAL);
			}
			else if ((((argv[j][i]) == '+') || ((argv[j][i]) == '-'))
			&& (is_num(argv[j][i + 1]) == SUCESS)
			&& (is_num(argv[j][i - 1]) == SUCESS))
				return (ERR_INVAL);
		}
	}
	return (SUCESS);
}
