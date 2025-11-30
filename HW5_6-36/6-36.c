#include <stdio.h>
#include <stdlib.h>

void stringReverse(const char *strArray);

int main()
{
    char str[] = "Hello World!";

    printf("Original string: %s\n", str);
    printf("Reversed string: ");

    stringReverse(str);

    printf("\n");
    system("pause");
    return 0;
}

void stringReverse(const char *strArray)
{
    if (*strArray == '\0')
    {
        return;
    }

    stringReverse(strArray + 1);

    printf("%c", *strArray);
}
