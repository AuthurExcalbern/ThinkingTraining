/* CodeForces 869B 2017-12-7

给两个数a和b，b>=a,求a!/b!的个位数值
0! = 1

分析：
注意考虑各种情况即可
*/

#include<cstdio>

int main(void)
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    if(a == 0) a=1;
    if(b == 0) b=1;
    int tmp = 1;
    if(a == b) printf("%d\n", tmp);
    else if(a+1 == b) {tmp = b%10; printf("%d\n", tmp );}
    else
    {
        long long int c = b - a;
        int ans = b % 10;
        b--;
        for(long long int i = 1; i < c; i++)
        {
            if(ans == 0) break;
            ans = (ans * (b % 10)) % 10;
            b--;
        }
        printf("%d\n", ans);
        return 0;
    }
 }
