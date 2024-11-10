#include<stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int a[N], max=0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]> max){
            max = a[i];
        }
        

    }

    printf("%d ", max);
    

    return 0;
}