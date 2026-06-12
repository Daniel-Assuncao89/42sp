/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:38:04 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/11 19:12:37 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
char	*get_next_line(int fd);
int		verify_line(char *line_str);
int		line_len(char *line_str);


#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
