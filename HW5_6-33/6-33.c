#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

int binarySearch(const int b[], int low, int high, int searchKey);
void printHeader();
void printRow(const int b[], int low, int mid, int high);

int main()
{
    int a[SIZE];
    int i;
    int key;
    int result;

    for (i = 0; i < SIZE; i++) {
        a[i] = 2 * i;
    }

    printf("Enter a number between 0 and 28: ");
    scanf("%d", &key);

    printHeader();

    result = binarySearch(a, 0, SIZE - 1, key);

    if (result != -1) {
        printf("\n%d found in array element %d\n", key, result);
    } else {
        printf("\n%d not found\n", key);
    }

    system("pause");
    return 0;
}

int binarySearch(const int b[], int low, int high, int searchKey)
{
    int middle;

    if (low > high) {
        return -1;
    }

    middle = (low + high) / 2;

    printRow(b, low, middle, high);

    if (searchKey == b[middle]) {
        return middle;
    }
    else if (searchKey < b[middle]) {
        return binarySearch(b, low, middle - 1, searchKey);
    }
    else {
        return binarySearch(b, middle + 1, high, searchKey);
    }
}

void printHeader()
{
    int i;
    printf("\nSubscripts:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("----");
    }
    printf("\n");
}

void printRow(const int b[], int low, int mid, int high)
{
    int i;
    for (i = 0; i < SIZE; i++) {
        if (i < low || i > high) {
            printf("    ");
        } 
        else if (i == mid) {
            printf("%3d*", b[i]);
        } 
        else {
            printf("%3d ", b[i]);
        }
    }
    printf("\n");
}
