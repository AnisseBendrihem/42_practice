/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:42:25 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/21 21:57:09 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		lenof_newline(char *str);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strndup(char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char **static_recip, char **read_recip);
char	*next_and_free(char **static_recip, int bytes_read);
int		init_var(int fd, char **final_line, char **read_recip,
			ssize_t *bytes_read);

char	*get_next_line(int fd);

#endif
