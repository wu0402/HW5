#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 13       
#define ROLLS 36000 

int main()
{
    int face1;
    int face2;
    int sum;
    int roll;
    int frequency[SIZE] = { 0 };

    srand(time(NULL));

    for (roll = 1; roll <= ROLLS; roll++)
    {
        face1 = 1 + rand() % 6;
        face2 = 1 + rand() % 6;
        sum = face1 + face2;
        frequency[sum]++;
    }

    printf("%s%15s%15s\n", "點數總和", "出現次數", "實際百分比");
    printf("----------------------------------------\n");

    for (sum = 2; sum <= 12; sum++)
    {
        double percent = (double)frequency[sum] / ROLLS * 100;
        printf("%4d%15d%14.2f%%\n", sum, frequency[sum], percent);
    }

    printf("----------------------------------------\n");

    printf("\n[合理性驗證]\n");
    printf("理論上 7 點出現的機率為 6/36 = 1/6 (約 16.67%%)\n");
    printf("期望次數為: 36000 * 1/6 = 6000 次\n");
    printf("實際次數為: %d 次\n", frequency[7]);

    int diff = abs(frequency[7] - ROLLS/6);
    if (diff < 200) {
        printf("結論: 結果合理，非常接近理論值。\n");
    } else {
        printf("結論: 結果偏差較大 (屬隨機波動)。\n");
    }

    system("pause");
    return 0;
}
