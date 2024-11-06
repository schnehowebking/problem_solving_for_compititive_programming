#include<stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int a[N], sum=0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        sum = sum+a[i];
    }

    printf("%d ", sum);
    

    return 0;
}