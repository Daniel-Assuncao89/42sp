/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:31:52 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/28 14:36:01 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		*range = (int *) malloc(size * sizeof(int));
		if (range == NULL)
			return (-1);
		while (i < size)
		{
			(*range)[i] = min;
			min++;
			i++;
		}
	}
	return (size);
}
/*
#include <stdio.h>
void check_null_case(int min, int max)
{
    int *arr = (int *)0x1234; // valor sentinela
    int size = ft_ultimate_range(&arr, min, max);

    if (size == 0 && arr == NULL)
        printf("[OK] NULL case (%d, %d)\n", min, max);
    else
        printf("[FAIL] NULL case (%d, %d)\n", min, max);
}

void check_values(int min, int max)
{
    int *arr;
    int size = ft_ultimate_range(&arr, min, max);
    int i;

    if (size != max - min)
    {
        printf("[FAIL] Size incorrect (%d, %d): got %d\n", min, max, size);
        return;
    }

    if (!arr)
    {
        printf("[FAIL] Returned NULL (%d, %d)\n", min, max);
        return;
    }

    i = 0;
    while (i < size)
    {
        if (arr[i] != min + i)
        {
            printf("[FAIL] Value error at index %d: got %d, expected %d\n",
                i, arr[i], min + i);
            free(arr);
            return;
        }
        i++;
    }

    printf("[OK] Values correct (%d, %d)\n", min, max);
    free(arr);
}

void check_pointer_assignment()
{
    int *arr = NULL;
    ft_ultimate_range(&arr, 0, 5);

    if (arr == NULL)
        printf("[FAIL] Pointer not assigned\n");
    else
        printf("[OK] Pointer correctly assigned\n");

    free(arr);
}

void check_independent_memory()
{
    int *arr1;
    int *arr2;

    ft_ultimate_range(&arr1, 0, 5);
    ft_ultimate_range(&arr2, 0, 5);

    if (arr1 == arr2)
        printf("[FAIL] Same memory returned\n");
    else
        printf("[OK] Different memory allocated\n");

    free(arr1);
    free(arr2);
}

void check_large_range()
{
    int *arr;
    int size = ft_ultimate_range(&arr, -1000, 1000);

    if (size != 2000)
    {
        printf("[FAIL] Large range size incorrect\n");
        return;
    }

    if (!arr)
    {
        printf("[FAIL] Large range returned NULL\n");
        return;
    }

    if (arr[0] != -1000 || arr[size - 1] != 999)
        printf("[FAIL] Large range values incorrect\n");
    else
        printf("[OK] Large range works\n");

    free(arr);
}

void check_edge_cases()
{
    int *arr;

    // min == max
    if (ft_ultimate_range(&arr, 5, 5) == 0 && arr == NULL)
        printf("[OK] Edge min == max\n");
    else
        printf("[FAIL] Edge min == max\n");

    // min > max
    if (ft_ultimate_range(&arr, 10, 5) == 0 && arr == NULL)
        printf("[OK] Edge min > max\n");
    else
        printf("[FAIL] Edge min > max\n");
}

int main(void)
{
    printf("==== FT_ULTIMATE_RANGE TESTER ====\n\n");

    // 🔴 NULL cases
    check_null_case(5, 5);
    check_null_case(10, 5);
    check_null_case(-3, -3);

    // 🟢 Valores corretos
    check_values(0, 1);
    check_values(1, 5);
    check_values(-5, 5);
    check_values(10, 15);

    // 🔵 Edge cases
    check_edge_cases();

    // 🧠 Ponteiro
    check_pointer_assignment();

    // 💥 Memória
    check_independent_memory();

    // 🚀 Stress
    check_large_range();

    printf("\n==== END TESTS ====\n");

    return 0;
}
*/
