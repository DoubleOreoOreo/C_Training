#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int nthUglyNumber(int n){
    int ans = 0;
    int x, y, z;
    int i = 0, j = 0, k = 0;
    vector<int> ugly;
    ugly.reserve(n);
    ugly.push_back(1);

    while(ugly.size() < n){
        x = 2 * ugly[i];
        y = 3 * ugly[j];
        z = 5 * ugly[k];
        ans = min(min(x, y), z);
        i = (ans == x) ? ++i: i;
        j = (ans == y) ? ++j: j;
        k = (ans == z) ? ++k: k;
        ugly.push_back(ans);
    }

    for (int i = 0; i<ugly.size(); i++)
        cout << ugly[i] << " ";

    return ugly.back();
}

int main()
{
    //printf("ans = %d\n", nthUglyNumber(100));
    /*int* array = (int*)malloc(sizeof(int));
    array[0] = 5;
    array[1] = 2;

    printf("%d\n", array[0]);
    printf("%d\n", array[1]);*/
    return 0;
}