/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:05:40 by mlaffita          #+#    #+#             */
/*   Updated: 2025/04/23 18:54:16 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
													// Mine:
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

int	main(int ac, char **ar)
{
	char	*t1;
	int		i;
	int		n;
	int		j;
	int		s;

	if (ac != 2)
	{
		perror("ERROR:");
		return (1);
	}
	else
	{
		i = 0;
		n = 0;
		j = 0;
		s = ft_strlen(ar[1]);
		t1=malloc(100001);
		if(!t1)
			return 1;
		n = read(0, t1, 100000);
		if (n <= 0)
		{
			free(t1);
			perror("ERROR:");
			return (1);
		}
		t1[n] = '\0'; 
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
	write(1, t1, n);
	free(t1);
	return (0);
}
