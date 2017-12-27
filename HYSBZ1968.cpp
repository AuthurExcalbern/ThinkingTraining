/* HYSBZ1986 2017-12-7
 * 
 * 题意：
 * 给一个数N，求它与它之前所有数的约数数目的和
 * 
 */

#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{
    int N;
    scanf("%d", &N);
    unsigned long long ans = 0;
    for(int i = 1; i < N; i++)
        ans += N/i;
    cout << ans << endl;
    return 0;
}