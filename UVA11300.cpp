/* UVA 11300 2017-11-21

桌子边坐n个人，每人有一定的金币，金币总数能被整除
每人的金币能给左右相邻的人，求如何移动最少的金币使所有人的金币相等

输入整数n(n<=1000000)
n行整数代表每人的金币，输入结束标志为EOF

输出被移动金币的最小值

Sample Input
3
100
100
100
4
1
2
5
4

Sample Output
0
4

解法：
算数解
第一人：A1-x1+x2=M -> x2=M-A1+x1=x1-C1(给最后一人x1金币，第二人给他x2金币)
第二人：A2-x2+x3=M -> x3=M-A2+x2=2M-A1-A2+x1=x1-C2
.......
我们希望xi尽量小，即|x1|+|x1-C1|+|x1-C2|+....最小
即为求出恰当的x1即可，x1应该为中位数

*/

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000000 + 10;
//A为每人有的金币数，C为上面的C数组，tot为金币总数，M为金币平均数
long long A[maxn], C[maxn], tot, M;

int main(void)
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        tot = 0;
        for(int i = 1; i <= n; i++) {scanf("%lld", A+i); tot += A[i];}
        M = tot / n;
        C[0] = 0;
        //递推求C数组值
        for(int i = 1; i <= n; i++) C[i] = C[i-1] + A[i] - M;
        sort(C, C+n);
        long long x1 = C[n/2], ans = 0;//x1取中位数
        for(int i = 0; i < n; i++) ans += abs(x1 - C[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
