#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int M, i, score, MAX=0;
    char* Name;
    int j=0;
    scanf("%d", &M);
    int ans[M];

    Name = (char*)malloc(M * sizeof(char));

    for (i = 0; i < M; i++)
    {
        scanf("%s%d", Name, &score);
        //printf("%s | %d\n", Name, score);
        if(score>=MAX)
        {
            MAX = score;
        }
    }

    printf("%s | %d\n", Name, MAX);
    printf("%s | %d\n", Name+1, MAX);

    free(Name);
    return 0;
}