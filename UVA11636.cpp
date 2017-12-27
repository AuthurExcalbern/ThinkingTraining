/* UVA 11636 Hello World! 2017-11-29

用复制粘贴来输出hello world，1->2->4->8....
最少几次才可以输出n句(0<n<=10 001)

Sample Input
2
10
-1

Sample Output
Case 1: 1
Case 2: 4

分析：
进行i次复制后最多可以有2^i句，当2^i > n时，i即为答案
可以用二进制的位移来优化

*/

#include<cstdio>

int main(void)
{
    int kase = 1;
    int n;
    while(scanf("%d", &n) == 1 && n >= 0)
    {
        int ans = 0;
        while(n > 1<<ans) ans++;//1<<ans = 2^ans
        printf("Case %d: %d\n", kase, ans);
        kase++;
    }
    return 0;
}
