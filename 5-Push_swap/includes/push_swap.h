/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:13:45 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 22:19:00 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int	*st_a;
	int	*st_b;
	int	size_tot;
	int	size_a;
	int	size_b;
	int	top_a;
	int	top_b;
	int	checker;
}				t_stack;

void			ft_check_sorted(t_stack *stacks);
void			ft_check_duplicate(t_stack *stacks, int s, int value);

void			ft_calloc_args(t_stack *stacks, int argc, char **argv);
int				ft_args_in_int(int start, int end, char *argv, t_stack *stacks);

char			**ft_split(char const *s, char c);

void			ft_fill_stack(t_stack *stacks, char **argv,
					int argc, int index);
size_t			ft_strlen(const char *s);
void			ft_fill_size_top(t_stack *stacks, int nbr_args);

void			ft_free_exit_error(t_stack *stacks);
void			ft_exit_error(void);
void			ft_free_exit_success(t_stack *stacks);
void			ft_free_exit_OK(t_stack *stacks);
void			ft_free_exit_KO(t_stack *stacks);

long			ft_atoi(const char *nptr, t_stack *stacks);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putendl(char *s, int fd);

void			swap_a(t_stack *stacks, int write);
void			swap_b(t_stack *stacks, int write);
void			swap_ab(t_stack *stacks, int write);

void			push_a(t_stack *stacks, int write);
void			push_b(t_stack *stacks, int write);

void			rotate_a(t_stack *stacks, int write);
void			rotate_b(t_stack *stacks, int write);
void			rotate(t_stack *stacks, int write);

void			re_rotate_a(t_stack *stacks, int write);
void			re_rotate_b(t_stack *stacks, int write);
void			re_rotate(t_stack *stacks, int write);

void			ft_small_algo(t_stack *stacks);

void			ft_big_algo(t_stack *stacks);

int				ft_first_a(t_stack *stacks);
int				ft_first_b(t_stack *stacks);
int				ft_second_a(t_stack *stacks, int first_a);
int				ft_last_a(t_stack *stacks);
int				ft_last_b(t_stack *stacks);

int				ft_previous_b(t_stack *stacks, int nbr);
int				ft_bottom_chunk(t_stack *stacks, int nbr_chu, int max);
int				ft_top_chunk(t_stack *stacks, int nbr_chu, int max);

void			ft_nbr_suite(t_stack *stacks, int first_a);

void			ft_chunk_algo(t_stack *stacks, int nbr_of_chunks);

void			ft_printf(t_stack *stacks);
void			ft_printf_st_ab(t_stack *stacks);

/*
** Checker
*/

void			ft_OK_or_KO(t_stack *stacks);

int				read_line(char *keep, int fd);
int				fill_line(char **line, int size, char *keep, int ret_read);
int				size_line(char **line, char *keep, int ret_read);
char			*join_keep_line(char *tmp, char *line, int i);
int				get_next_line(int fd, char **line);

void			init_keep(char *keep, int i);
int				ret_read_start(char *keep, int fd, char **line);

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif