#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void LIOJ1003();

int main()
{
    LIOJ1003();
    return 0;
}

void LIOJ1003()
{
    int n, m, i, index;
    char str[100], temp[10000], ans[10000];
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%s", str);
        strcat(temp, str);
    }
    scanf("%d", &m);
    
    for(i = 0; i < m; i++)
    {
        scanf("%d", &index);
        ans[i] = temp[index - 1];
    }
    printf("%s\n", ans);
}