/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgorner <pgorner@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:10:33 by pgorner           #+#    #+#             */
/*   Updated: 2023/02/17 15:28:25 by pgorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	is_num(char check)
{
	if (check == '0' || check == '1' || check == '2'
		|| check == '3' || check == '4' || check == '5'
		|| check == '6' || check == '7' || check == '8'
		|| check == '9')
		return (SUCESS);
	else
		return (ERR_INVAL);
}

int	size(char **count)
{
	int	i;

	i = -1;
	while (count[i + 1] != NULL)
		++i;
	return (i);
}

int	ft_error(int i)
{
	if (i == 1)
	{
		printf("ERROR \n");
		return (ERR_INVAL);
	}
	else
		return (SUCESS);
}

char	*join_inpt(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		c;

	c = argc;
	str = ft_strdup(ft_strjoin2(" ", argv[1]));
	i = 2;
	while (argv[i])
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	return (str);
}
