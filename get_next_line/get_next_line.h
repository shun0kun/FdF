/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:05:42 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/25 13:36:45 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*if_has_nl_get_line(char **p_stash);
char	*get_last_line(char **p_stash);
char	*buf_join(char **p_stash, char **p_buf);
char	*free1_and_return_null(char **p);
char	*free2_and_return_null(char **p1, char **p2);
bool	has_nl(char *s);
size_t	gnl_strlen(char *s);

#endif
