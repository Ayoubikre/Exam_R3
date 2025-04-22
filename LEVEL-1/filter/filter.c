/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:05:40 by mlaffita          #+#    #+#             */
/*   Updated: 2025/04/21 22:56:47 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

char	*ft_strdup(char *t)
{
	int		i;
	int		s;
	char	*str;

	i = 0;
	s = ft_strlen(t);
	str = malloc(s + 1);
	if (!str)
		return (NULL);
	while (t[i])
	{
		str[i] = t[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_check(char *t1, char *t2)
{
	int	s1;
	int	s2;
	int	i;

	s1 = ft_strlen(t1);
	s2 = ft_strlen(t2);
	i = 0;
	if (s1 < s2)
		return (0);
	while (t2[i] && t2[i] == t1[i])
		i++;
	if (i != s2)
		return (0);
	return (1);
}

void	ft_error(void)
{
	write(2, "ERROR:", 6);
	perror("try again");
}

int	main(int ac, char **ar)
{
	char	t1[100000];
	int		i;
	int		n;
	int		j;
	int		s;
	int		s2;

	if (ac != 2)
	{
		ft_error();
		return (1);
	}
	else
	{
		i = 0;
		n = 0;
		j = 0;
		s = ft_strlen(ar[1]);
		n = read(0, t1, 100000);
		if (n <= 0)
		{
			ft_error();
			return (1);
		}
		while (t1[i])
		{
			if (ft_check(t1 + i, ar[1]) == 1)
			{
				j = 0;
				while (j < s)
				{
					t1[i + j] = '*';
					j++;
				}
			}
			i++;
		}
	}
	s2 = ft_strlen(t1);
	write(1, t1, s2);
	return (0);
}
