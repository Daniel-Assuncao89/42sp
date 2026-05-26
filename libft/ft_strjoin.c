/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:57:37 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/26 19:25:22 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*concat;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	ft_strlcpy(concat, s1, s1_len + 1);
	ft_strlcat(concat, s2, s2_len + s1_len + 1);
	return (concat);
}
