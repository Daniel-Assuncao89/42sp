/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:32:51 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/28 13:25:04 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int size;

	if (min >= max)
		range = NULL;
	else
	{
		i = 0;
		size = max - min;
		range = (int *) malloc(size * sizeof(int));
		while (i < size)
		{
			range[i] = min;
			i++;
			min++;
		}
	}
	return (range);
}
/*
#include <stdio.h>
void check_null(int min, int max)
{
    int *arr = ft_range(min, max);

    if (arr == NULL)
        printf("[OK] ft_range(%d, %d) returned NULL\n", min, max);
    else
    {
        printf("[FAIL] ft_range(%d, %d) should return NULL\n", min, max);
        free(arr);
    }
}

void check_values(int min, int max)
{
    int *arr = ft_range(min, max);
    int size = max - min;
    int i;

    if (!arr)
    {
        printf("[FAIL] ft_range(%d, %d) returned NULL\n", min, max);
        return;
    }

    i = 0;
    while (i < size)
    {
        if (arr[i] != min + i)
        {
            printf("[FAIL] Wrong value at index %d: got %d, expected %d\n",
                i, arr[i], min + i);
            free(arr);
            return;
        }
        i++;
    }

    printf("[OK] ft_range(%d, %d) values correct\n", min, max);
    free(arr);
}

void check_memory_independence()
{
    int *arr1 = ft_range(0, 5);
    int *arr2 = ft_range(0, 5);

    if (!arr1 || !arr2)
    {
        printf("[FAIL] Memory allocation failed\n");
        return;
    }

    if (arr1 == arr2)
        printf("[FAIL] Same pointer returned\n");
    else
        printf("[OK] Different memory allocated\n");

    free(arr1);
    free(arr2);
}

void check_large_range()
{
    int min = -1000;
    int max = 1000;
    int *arr = ft_range(min, max);

    if (!arr)
    {
        printf("[FAIL] Large range returned NULL\n");
        return;
    }

    if (arr[0] != min || arr[max - min - 1] != max - 1)
        printf("[FAIL] Large range values incorrect\n");
    else
        printf("[OK] Large range works\n");

    free(arr);
}

int main(void)
{
    printf("==== FT_RANGE MOULINETTE TESTER ====\n\n");

    // 🔴 NULL cases
    check_null(5, 5);
    check_null(10, 5);
    check_null(-3, -3);

    // 🟢 Basic correct cases
    check_values(0, 1);
    check_values(1, 5);
    check_values(-5, 5);
    check_values(10, 15);

    // 🔵 Edge cases
    check_values(-1, 0);
    check_values(-10, -5);

    // 🧠 Memory checks
    check_memory_independence();

    // 🚀 Stress test
    check_large_range();

    printf("\n==== END TESTS ====\n");

    return 0;
}
*/
