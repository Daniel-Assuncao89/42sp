/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:15:37 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/28 12:32:24 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *) malloc(ft_strlen(src) * sizeof(char));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

void test_basic()
{
    char *s = ft_strdup("Hello");
    printf("[BASIC] %s\n", s);
    free(s);
}

void test_empty()
{
    char *s = ft_strdup("");
    printf("[EMPTY] '%s'\n", s);
    free(s);
}

void test_single_char()
{
    char *s = ft_strdup("A");
    printf("[SINGLE CHAR] %s\n", s);
    free(s);
}

void test_long_string()
{
    char *s = ft_strdup("Lorem ipsum dolor sit amet");
    printf("[LONG STRING] %s\n", s);
    free(s);
}

void test_special_chars()
{
    char *s = ft_strdup("42\nSP\tTeste!");
    printf("[SPECIAL CHARS]\n%s\n", s);
    free(s);
}

void test_null_terminator()
{
    char *s = ft_strdup("abc");
    if (s[3] == '\0')
        printf("[NULL TERMINATOR] OK\n");
    else
        printf("[NULL TERMINATOR] FAIL\n");
    free(s);
}

void test_independence()
{
    char src[] = "Hello";
    char *dup = ft_strdup(src);

    src[0] = 'X';

    printf("[INDEPENDENCE]\n");
    printf("src: %s\n", src);
    printf("dup: %s\n", dup);

    free(dup);
}

void test_pointer_difference()
{
    char *s1 = "Test";
    char *s2 = ft_strdup(s1);

    printf("[POINTER DIFFERENCE]\n");
    printf("s1: %p\n", (void *)s1);
    printf("s2: %p\n", (void *)s2);

    if (s1 != s2)
        printf("OK: Different memory\n");
    else
        printf("FAIL: Same memory\n");

    free(s2);
}

void test_multiple_cases()
{
    char *tests[] = {
        "Hello",
        "",
        "A",
        "42",
        "Lorem ipsum dolor sit amet",
        "Line\nBreak",
        "Tab\tTest"
    };

    int i = 0;
    char *dup;

    printf("[MULTIPLE TESTS]\n");

    while (i < 7)
    {
        dup = ft_strdup(tests[i]);
        printf("Original: %s\n", tests[i]);
        printf("Duplicate: %s\n", dup);
        printf("Same address? %d\n\n", tests[i] == dup);
        free(dup);
        i++;
    }
}

int main(void)
{
    printf("==== FT_STRDUP TESTER ====\n\n");

    test_basic();
    test_empty();
    test_single_char();
    test_long_string();
    test_special_chars();
    test_null_terminator();
    test_independence();
    test_pointer_difference();
    test_multiple_cases();

    printf("\n==== END TESTS ====\n");

    return (0);
}
*/
