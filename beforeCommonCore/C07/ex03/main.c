#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(int size, char **strs, char *sep);

void	test(char *name, char *result, char *expected)
{
	if (!result && !expected)
	{
		printf("[OK]   %s\n", name);
		return;
	}
	if (result && expected && strcmp(result, expected) == 0)
		printf("[OK]   %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		printf("Expected: \"%s\"\n", expected ? expected : "NULL");
		printf("Got     : \"%s\"\n\n", result ? result : "NULL");
	}
	if (result)
		free(result);
}

int	main(void)
{
	char	*arr1[] = {"abc", "123", "xyz"};
	char	*arr2[] = {"A", "B", "C"};
	char	*arr3[] = {"hello", "world"};
	char	*arr4[] = {"only"};
	char	*arr5[] = {"ignore", "this"};
	char	*arr6[] = {"", "", ""};
	char	*arr7[] = {"abc", "", "123"};
	char	*arr8[] = {"x", "y"};
	char	*arr9[] = {"longstring", "test"};

	test("basic",
		ft_strjoin(3, arr1, "-"),
		"abc-123-xyz");

	test("long separator",
		ft_strjoin(3, arr2, " - "),
		"A - B - C");

	test("empty separator",
		ft_strjoin(2, arr3, ""),
		"helloworld");

	test("single string",
		ft_strjoin(1, arr4, "-"),
		"only");

	test("size 0",
		ft_strjoin(0, arr5, "-"),
		"");

	test("empty strings",
		ft_strjoin(3, arr6, "-"),
		"--");

	test("mixed empty",
		ft_strjoin(3, arr7, "-"),
		"abc--123");

	test("complex sep",
		ft_strjoin(2, arr8, "***"),
		"x***y");

	test("no sep needed",
		ft_strjoin(2, arr9, ""),
		"longstringtest");

	return (0);
}
