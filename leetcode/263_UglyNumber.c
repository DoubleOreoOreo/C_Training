#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isUgly(int n){
    int prime[3] = {2, 3, 5};
    int i = 0;
    
    if (n == 1){
        return true;
    }else if (n < 1){
        return false;
    }else{
        for (i = 0; i < 3; i++){
            while(n%prime[i] == 0)
                n = n/prime[i]; 
        }
        return (n>1) ? false : true;
    }
}

int main()
{
    int Number = 210;
    printf("%d", isUgly(Number));
    return 0;
}