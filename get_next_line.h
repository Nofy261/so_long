/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:56:29 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/03 11:56:44 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoinfree(char *stash, char *buffer);
int		ft_strchr(char *s, int c);

#endif