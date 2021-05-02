#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define DIGITS 512
typedef const char* String;

struct BigNumber
{
    int array[1000];    // 一格存一個數字，可以存1000個位數
    bool sign;          // 正負號
    int length;         // 位數
}A, B;

//僅適用正整數
void scan(char s[DIGITS], int a[DIGITS])
{
    int i = DIGITS - 1;            // 大數的數字位置
    int j = 0, n = strlen(s);   // 字串的字元位置
    while (i >= n) a[i--] = 0;  // 開頭一律填零
    while (i >= 0) a[i--] = s[j++] - '0';   // 字串頭尾顛倒，存入陣列
}

void print(int a[DIGITS])
{
    int i = DIGITS - 1; // 大數的數字位置
    while (i >= 0 && a[i] == 0) i--; // 數字開頭的零都不印
 
    if (i < 0)
        printf("%d", 0);
    else
        while (i >= 0) printf("%d", a[i--]);
}

int largerthan(int a[DIGITS], int b[DIGITS])
{
    // 從高位數開始比，對應的位數相比較。
    for (int i=DIGITS-1; i>=0; i--)
    {
        if (a[i] > b[i])   // 一旦a比較大，回傳1。
            return 1;
        else if (a[i] < b[i])   // 一旦b比較大，回傳-1。
            return -1;
    }
    return 0;
}

void LIOJ1004()
{
    int M, i, k;
    scanf("%d", &M);
    String ans[M];
    char a[DIGITS], b[DIGITS];

    for (i = 0; i < M; i++)
    {
        scanf("%s%s%d", a, b, &k);
        scan(a, A.array);
        scan(b, B.array);
        if (k<0){
            if(largerthan(A.array, B.array)<0)
                ans[i] = "A";
            else if(largerthan(A.array, B.array)>0)
                ans[i] = "B";
            else
                ans[i] = "DRAW";
        }else{
            if(largerthan(A.array, B.array)>0)
                ans[i] = "A";
            else if(largerthan(A.array, B.array)<0)
                ans[i] = "B";
            else
                ans[i] = "DRAW";
        }
    }
    for (i = 0; i < M; i++)
        printf("%s\n", ans[i]);
}

int main()
{
    LIOJ1004();
    return 0;
}