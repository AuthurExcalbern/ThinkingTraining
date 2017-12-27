/* UVA 11464 2017-11-23

给一个n×n的01矩阵，要求把尽量少的0变成1,使得每个元素的上下左右的元素（如果存在）的和为偶数

输入：
数据组数T（T<=30）
正整数n（1<=n<=15)
接下来n行包含n个非0即1的整数

输出：
输出改变元素的最小个数，无解输出-1

Sample Input
3
3
0 0 0
0 0 0
0 0 0
3
0 0 0
1 0 0
0 0 0
3
1 1 1
1 1 1
0 0 0

Sample Output
Case 1: 0
Case 2: 3
Case 3: -1

解法：
暴力枚举要2^255种情况过多了
n只有15,第一行只有2^15=32768种情况，可以枚举第一行然后计算第二行情况
第二行又能推出第三行，复杂度为O(2^n * n^2)

*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 20;
const int INF = 1000000000;
int n, A[maxn][maxn], B[maxn][maxn];

int check(int s)
{
    memset(B, 0, sizeof(B));
    for(int c = 0; c < n; c++)
    {
        if(s & (1<<c)) B[0][c] = 1;//mmp
        else if(A[0][c] == 1) return INF;//1不能变成0
    }
    for(int r = 1; r < n; r++)
        for(int c = 0; c < n; c++)
        {
            int sum = 0;//元素B[r-1][c]的上左右3元素之后和
            if(r > 1) sum += B[r-2][c];
            if(c > 0) sum += B[r-1][c-1];
            if(c < n-1) sum += B[r-1][c+1];
            B[r][c] = sum % 2;//依据上一级计算出下一级情况
            if(A[r][c] == 1 && B[r][c] == 0) return INF;//1不能变成0
        }
    int cnt = 0;
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++) if(A[r][c] != B[r][c]) cnt++;
    return cnt;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++)
    {
        //读入数据与初始化
        scanf("%d", &n);
        for(int r = 0; r < n; r++)
            for(int c = 0; c < n; c++) scanf("%d", &A[r][c]);
        int ans = INF;

        //列举2^n种情况
        for(int s = 0; s < (1<<n); s++) ans = min(ans, check(s));

        if(ans == INF) ans = -1;
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}
