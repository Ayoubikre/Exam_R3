/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:59:11 by noctis            #+#    #+#             */
/*   Updated: 2025/04/22 01:55:11 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_str(va_list ptr)
{
	int		i;
	char	n;
	char	*t;

	i = 0;
	t = va_arg(ptr, char *);
	while ((n = fgetc(stdin)) != EOF)
	{
		if (isspace(n))
			break ;
		t[i] = n;
		i++;
	}
	t[i] = '\0';
	if (i == 0)
		return (EOF);
	return (1);
}

int	ft_char(va_list ptr, int f)
{
	char	*c;
	int		i;

	c = va_arg(ptr, char *);
	i = 0;
	if (f == 1)
	{
		while ((*c = fgetc(stdin)) != EOF && isspace(*c))
			;
	}
	else
		*c = fgetc(stdin);
	if (*c == EOF)
		return (EOF);
	return (1);
}

int	ft_num(va_list ptr)
{
	char	c;
	long	i;
	long	*n;
	long	f;

	i = 0;
	f = 1;
	n = va_arg(ptr, long *);
	while ((c = fgetc(stdin)) != EOF && isspace(c))
		;
	if (c == '-' || c == '+')
	{
		if (c == '-')
		{
			f *= -1;
		}
	}
	else
		ungetc(c, stdin);
	while ((c = fgetc(stdin)) != EOF && isdigit(c))
	{
		i = (i * 10) + (c - '0');
	}
	*n = i * f;
	if (c == EOF && i == 0)
		return (EOF);
	return (1);
}

int	ft_scanf(const char *t, ...)
{
	int		i;
	int		count;
	int		n;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, t);
	if (!t)
		return (-1);
	while (t[i])
	{
		if (t[i] == '%' && t[i + 1] != '\0')
		{
			if (t[i + 1] == 's')
			{
				n = ft_str(ptr);
				if (n != EOF)
					count++;
				else
					break ;
			}
			else if (t[i + 1] == 'd')
			{
				n = ft_num(ptr);
				if (n != EOF)
					count++;
				else
					break ;
			}
			else if (t[i + 1] == 'c')
			{
				if (i == 0 || (i != 0 && t[i - 1] != ' '))
				{
					n = ft_char(ptr, 0);
					if (n != EOF)
						count++;
					else
						break ;
				}
				else
				{
					n = ft_char(ptr, 1);
					if (n != EOF)
						count++;
					else
						break ;
				}
			}
		}
		i++;
	}
	va_end(ptr);
	return (count);
}

int	main(void)
{
	long	num;
	char	t[100];
	int		n;

	// Testing %d input
	printf("Enter a number: ");
	n = ft_scanf("%d%s", &num, t);
	printf("You entered: %ld-%s-%d", num, t, n);
	return (0);
}
