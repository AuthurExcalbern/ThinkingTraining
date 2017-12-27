/* UVA 11292 2017-11-22 12:42

有一头有n个头的龙，你希望能杀死它（砍掉它所有的头
有m个骑士可以雇佣，能力值为x的骑士可以砍掉龙一个直径不超过x的头，且需要付x个金币，如何用最少的金币杀死龙
每一个骑士只能被雇佣一次，只能砍一个头

开始输入n和m（1<=n,m<=20000）
然后有n行代表龙头的直径，有m行代表骑士的能力

Sample Input
2 3
5
4
7
8
4
2 1
5
5
10
0 0
Sample Output
11
Loowater is doomed!//无解情况

解法：
对龙头直径数组和骑士能力数组进行排序后即可解决

 */

#include<cstdio>
#include<algorithm>

int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && n*m)
    {
        int l[n], q[m];//龙头数组和骑士数组
        for(int i = 0; i < n; i++) scanf("%d", l+i);
        for(int i = 0; i < m; i++) scanf("%d", q+i);
        std::sort(l, l+n);
        std::sort(q, q+m);

        int temp = 0, ans = 0;
        for(int i = 0; i < m; i++)
        {
            if(temp < n && q[i] >= l[temp]) {ans += q[i];temp++;}
            else if(temp >= n) break;
        }
        if(temp == n) printf("%d\n", ans);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
