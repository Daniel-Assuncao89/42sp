/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:48:54 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/20 15:45:40 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Função auxiliar interna para verificar se o buffer lido contém '\n'.
** Como o buffer acabou de ser preenchido, varremos apenas o tamanho dele,
** tornando a busca extremamente rápida.
*/
static int	has_newline(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
** CORRIGIDO: Agora o loop checa apenas o 'buff' (que tem tamanho fixo de BUFFER_SIZE)
** em vez de varrer a 'left_str' inteira que cresce infinitamente.
*/
static char	*read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	// Só continuamos lendo se a left_str não tiver \n E se o read ainda trouxer dados
	while (!has_newline(left_str) && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

static char	*get_line_extracted(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	// Aloca espaço considerando se parou no '\n' ou no '\0'
	str = (char *)malloc(sizeof(char) * (i + (left_str[i] == '\n') + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char *new_left_str(char *left_str)
{
    int     i;
    int     j;
    char    *str;

    // 1. Avança até encontrar o '\n' ou o fim da string
    i = 0;
    while (left_str[i] && left_str[i] != '\n')
        i++;
    
    // Se chegou no '\0', significa que não sobrou nada após a linha extraída
    if (!left_str[i])
    {
        free(left_str);
        return (NULL);
    }
    
    // 2. Aloca o espaço necessário para a sobra
    // O tamanho da sobra é: Tamanho total menos tudo que veio antes e incluindo o '\n' (i + 1)
    // +1 no final para a vaga do '\0'
    str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i));
    if (!str)
    {
        free(left_str); // Boa prática: liberar a left_str se o malloc falhar
        return (NULL);
    }
    
    // 3. i++ pula o '\n' para começarmos a copiar exatamente o que sobrou
    i++;
    j = 0;
    while (left_str[i])
        str[j++] = left_str[i++];
    str[j] = '\0';
    
    // 4. Libera a memória antiga e retorna a nova string limpa com a sobra
    free(left_str);
    return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_line_extracted(left_str);
	left_str = new_left_str(left_str);
	return (line);
}
