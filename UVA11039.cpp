/* UVA 11039 Building designing 2017-11-29

有n个绝对值不同的非0整数，选出尽量多的数，使正负号交替，而且绝对值递增
输入整数n(1<=n<=500 000)，输出最长序列长度

Sample Input
2
5
7
-2
6
9
-3
8
11
-9
2
5
18
17
-15
4

Sample Output
2
5

分析：
可以设两个数组，一个数组对输入的整数的绝对值进行排序
设另一个数组对负数进行标记，然后输出

*/

#include<cstdio>
#include<cstring>
#include<algorithm>
int a[500010], b[500010];
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            if(temp > 0) a[i] = temp;
            else {a[i] = -temp; b[-temp]++;}
        }
        std::sort(a, a+n);
        int ans = 1, t;
        if(b[a[0]] == 1) t = 1;
        else t = 0;
        for(int i = 1; i < n; i++)
        {
            if(b[a[i]] == 1 && t == 0) {ans++; t = 1;}
            else if(b[a[i]] == 0 && t == 1) {ans++; t = 0;}
        }
        printf("%d\n", ans);
    }
    return 0;
}
