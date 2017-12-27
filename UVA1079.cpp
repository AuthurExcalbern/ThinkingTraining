/* UVA 10795 2017-11-26

有n个大小各异的盘子，给一个初始局面一个目标局面，求最少要多少步
大盘子不能放在小盘子上面


输入：
第一行为正整数n(1<=n<=60)
第二行包含n个1～3的整数，为初始局面每个盘子所在的柱子编号
第三行同上，为目标局面

输出：最少所需要的步数

Sample Input
3
1 1 1
2 2 2
3
1 2 3
3 2 1
4
1 1 1 1
1 1 1 1
0

Sample Output
Case 1: 7
Case 2: 3
Case 3: 0

分析：
1.编号最大的盘子如果在初始局面和目标局面中的位置一样则不用移动
2.设最大的需移动的盘子为k，比k大的盘子可以无视
3.设一个参考局面：
如果k需要从1柱子移动到2柱子，则比k小的盘子都已经在3柱子，3柱子的盘子为：1,2,,,,k-1
4.初始->目标 = 初始->参考 + 目标->参考
5.递归计算上面的盘子
(答案要用long long)

*/

#include<cstdio>

//表示已知各盘子的初始编号数组P，求将盘子1,2,,,i全部移到柱子fina所需要的步数
long long f(int * P, int i, int fina)
{
    if(i == 0) return 0;//无盘子需要移动
    //第i盘已经在目标柱子fina上，递归求i-1盘所需的步数
    if(P[i] == fina) return f(P, i-1, fina);
    //因为1+2+3=6,所以可以由初始柱子P[i]和目标柱子fina推出可放置盘子的中转柱子：6-P[i]-fina
    //要移动i盘就要把i-1盘放到那中转柱子那里：f(P, i-1, 6-P[i]-fina)
    //然后再移动i盘(这里需要一步
    //再把i-1个盘子从一个柱子整体移动到另一个柱子，根据汉塔结论需要2^(i-1) - 1步
   //所以f(P,i,fina)=f(P,i-1,6-P[i]-fina)+2^(i-1)
    return f(P, i-1, 6-P[i]-fina) + (1LL << (i-1));
}

const int maxn = 60 + 10;
int n, start[maxn], finish[maxn];

int main(void)
{
    int kase = 1;
    while(scanf("%d", &n) == 1 && n)
    {
        //输入初始局面和目标局面，并从最大（最后面）开始查找出最大的需移动的盘子为k
        for(int i = 1; i <= n; i++) scanf("%d", start+i);
        for(int i = 1; i <= n; i++) scanf("%d", finish+i);
        int k = n;
        while(k >=1 && start[k] == finish[k]) k--;

        long long ans = 0;
        if(k >= 1)
        {
            int other = 6-start[k]-finish[k];
            ans = f(start, k-1, other) + f(finish, k-1, other) + 1;//移动k需要+1
        }
        printf("Case %d: %lld\n", kase, ans);
        kase++;
    }
    return 0;
}
