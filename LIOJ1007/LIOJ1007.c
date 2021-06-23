#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STUdata STUdata;
struct STUdata
{
    char Name[21];
    int score;
};

int main()
{
    int M, i, MAX=0;
    scanf("%d", &M);
    STUdata student[M];

    for (i = 0; i < M; i++)
    {
        scanf("%s%d", student[i].Name, &student[i].score);
        if(student[i].score>=MAX)
            MAX = student[i].score;
    }

    for (i = 0; i < M; i++)
    {
        if(student[i].score == MAX)
            printf("%s\n", student[i].Name);
    }
    
    return 0;
}