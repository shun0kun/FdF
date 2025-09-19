/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimots <sshimots@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:41:10 by sshimots          #+#    #+#             */
/*   Updated: 2025/09/19 17:39:18 by sshimots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// int		main(void);
char	*get_next_line(int fd);
char	*extend(char *stash, char *s);
char	*get_line_and_trim(char *stash);
char	*free_and_return_null(char **p1, char **p2);
bool	has_line_break(char *s);
void	free_and_nullify(char **p);
size_t	gnl_strlen(char *s);

#endif