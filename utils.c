/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:33:36 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/22 13:16:44 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', total_size);
	return (ptr);
}

// void    *ft_calloc(size_t nmemb, size_t size) // modif
// {
//     void    *ptr;
//     size_t    total_size;

//     if (!nmemb || !size)
//         return (malloc(0));
//     if (nmemb > (size_t) - 1 / size)
//         return (NULL);
//     total_size = nmemb * size;
//     ptr = malloc(total_size);
//     if (!ptr)
//         return (NULL);
//     ft_memset(ptr, '\0', total_size);
//     return (ptr);
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

