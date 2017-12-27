/* UVA 11078 Open Credit System 2017-11-29

给一个长度为n的数组，找出两整数Ai和Aj（i<j），使Ai-Aj尽量大

输入：
第一行：数据组数T（T<=20）
每组数据：
第一行：数组长度n(2<=n<=100 000)
n行每行为一个绝对值不超过150 000的整数

输出：Ai-Aj的最大值

Sample Input
3
2
100
20
4
4
3
2
1
4
1
2
3
4

Sample Output
80
3
-1

分析：
用暴力解时时间复杂度为n^2，不能处理100 000的数据规模
我们在取Aj时只要去前面Ai的最大值，这样只需要维护一个MaxAi，而时间复杂度可以降为n

*/

#include<cstdio>
#include<algorithm>
using namespace std;

int A[100000], n;

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", A+i);
        int ans = A[0] - A[1];
        int MaxAi = A[0];//动态维护A[0]~A[j-1]的最大值
        for(int j = 1; j < n; j++)//j=0时没有i
        {
            ans = max(ans, MaxAi - A[j]);
            MaxAi = max(A[j], MaxAi);//MaxAi晚于ans更新
        }
        printf("%d\n", ans);
    }
    return 0;
}
