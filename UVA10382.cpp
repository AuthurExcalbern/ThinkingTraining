/* UVA 10382 Watering Grass 2017-11-29

有一块草坪，长为l，宽为w。在其中心线不同位置有n个点状的喷水装置。
每个喷水装置i可以将以他为中心，半径为ri的圆形区域湿润，最少需要多少个喷水装置把草坪都弄湿？

输入：
第一行：n l w (1<=n<=10 000)
n行两整数：pi和ri

输出：
输出最少所需的装置数量，无解则输出-1

Sample Input
8 20 2
5 3
4 1
1 2
7 2
10 2
13 3
16 2
19 4
3 10 1
3 5
9 3
6 1
3 10 1
5 3
1 1
9 1

Sample Output
6
2
-1

分析：
通过圆形的半径和草坪的宽可以计算出一个装置所能湿润的一个长方形区域的长，
这会在草坪的长中形成一个个区域
然后按区域的左界进行排序，分析取出右界，得出答案

*/

#include<cstdio>
#include<cmath>
#include<algorithm>

struct sg//记录各个区间的左值l和右值r
{
    double l, r;
    sg(){}
    sg(double ll, double rr) { l = ll; r = rr; }
}s[10005];

//按从小到大排序
bool comp(sg a, sg b) { return a.l < b.l; }

//计算得出答案
int solve(int n, double m)
{
    std::sort(s, s+n, comp);
    double r = 0;//r为当前状态的最右界
    int p = 0, ans = 0;//p用于遍历
    while(r < m)//m就是草坪的长度
    {
        double rr = r;
        //当还有装置未遍历且未遍历装置的左值还小于/等于当前状态的最右界
        while(p < n && s[p].l <= r)
        {
            //记录所有满足条件的装置的最大的右值
            if(s[p].r > rr) rr = s[p].r;
            p++;
        }
        if(rr == r) return -1;//上面没有满足条件的装置能刷新右值时即为无解
        ans++;//所需的装置加一
        r = rr;//更新最右界
    }
    return ans;
}

int main(void)
{
    int n;
    double l, w;
    while(scanf("%d %lf %lf", &n, &l, &w) == 3)
    {
        int cnt = 0;
        w /= 2;//只取二分之一来用于计算
        for(int i = 0; i < n; i++)
        {
            double p, r;
            scanf("%lf %lf", &p, &r);
            if(r <= w) continue;//当直径都达不到草坪的宽时舍弃
            s[cnt++] = sg(p-sqrt((double)(r*r-w*w)),p+sqrt((double)(r*r-w*w)));//计算区间左右界
        }
        printf("%d\n", solve(cnt, l));
    }
    return 0;
}
