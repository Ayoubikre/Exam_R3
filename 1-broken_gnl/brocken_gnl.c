/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brocken_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:05:13 by mlaffita          #+#    #+#             */
/*   Updated: 2025/04/29 19:21:07 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

				    				// Mine:

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *ft_strdup(const char *str)
{
    char    *copy;
    int        i;

    copy = (char *)malloc(sizeof(char) * strlen(str) + 1);
    if (copy == NULL)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *get_next_line(int fd)
{
    static char    buffer[BUFFER_SIZE];
    char        line[100001];
    static int    n;
    static int    b_pos;
    int            i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    while (1337)
    {
        if (b_pos >= n)
        {
            n = read(fd, buffer, BUFFER_SIZE);
            b_pos = 0;
            if (n <= 0)
            {
                n=0;
                b_pos=0;
                break ;
            }
        }
        line[i++] = buffer[b_pos++];
        if (buffer[b_pos - 1] == '\n'|| i>100000)
            break ;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}
