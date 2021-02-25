/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:32:35 by ebodart           #+#    #+#             */
/*   Updated: 2021/02/25 17:27:54 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		fill_line(char **line, long int size, char *keep, int ret_read);
int		size_line(char **line, char *keep, int ret_read);
char	*join_keep_line(char *tmp, char *line, int i);
int		next_line(char *keep, int fd, char **line);
int		get_next_line(int fd, char **line);

int		read_line(char *keep, int fd);
void	init_keep(char *keep, long int i);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
