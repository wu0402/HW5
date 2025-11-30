#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int recursiveMaximum(const int array[], int size);

int main()
{
    int a[SIZE] = { 34, 12, 89, 5, 67, 99, 1, 45, 23, 78 };
    int i;
    int maxResult;

    printf("Array elements: ");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }

    maxResult = recursiveMaximum(a, SIZE);

    printf("\nMaximum value is: %d\n", maxResult);

    system("pause");
    return 0;
}

int recursiveMaximum(const int array[], int size)
{
    if (size == 1)
    {
        return array[0];
    }

    int maxOfRest = recursiveMaximum(array + 1, size - 1);

    if (array[0] > maxOfRest)
    {
        return array[0];
    }
    else
    {
        return maxOfRest;
    }
}
