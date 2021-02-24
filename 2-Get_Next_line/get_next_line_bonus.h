/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:32:35 by ebodart           #+#    #+#             */
/*   Updated: 2021/02/24 09:05:09 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FILE 256

int		read_line(char *keep, int fd);
int		fill_line(char **line, int size, char *keep, int ret_read);
int		size_line(char **line, char *keep, int ret_read);
char	*join_keep_line(char *tmp, char *line, int i);
int		get_next_line(int fd, char **line);

void	init_keep(char *keep, int i);
size_t	ft_strlen(const char *s);

int main(int argc, char **argv);

#endif
