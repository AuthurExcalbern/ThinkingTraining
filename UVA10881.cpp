/* UVA 10881 2017-11-22

一根L长的木棍上有n只蚂蚁，蚂蚁左右爬动，相撞就一起掉头
给出蚂蚁初始位置，求每只蚂蚁T秒后的位置

输入L,T,n(0<=n<=10000)
n行描述每只蚂蚁位置与移动方向，L向左，R向右

输出n行蚂蚁的状态，有掉下木棍的蚂蚁输出Fell off

Sample Input
2
10 1 4
1 R
5 R
3 L
10 R
10 2 3
4 R
5 L
8 R

Sample Output
Case #1:
2 Turning
6 R
2 Turning
Fell off
Case #2:
3 L
6 R
10 R

解法：
每只蚂蚁相撞可以看为“穿过”，关键在于求出T秒后那蚂蚁是“谁”

*/

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 5;

struct Ant
{
    int id;//输入顺序
    int p;//位置
    int d;//朝向，-1向左，1向右，0转身
    //按p排序
    bool operator < (const Ant & a) const { return p < a.p;}
}before[maxn], after[maxn];

const char dirName[][10] = {"L", "Turning", "R"};

int order[maxn];//输入的第i蚂蚁是终态中的第order[i]只蚂蚁

int main(void)
{
    int K;
    scanf("%d", &K);
    for(int kase = 1; kase <= K; kase++)
    {
        int L, T, n;
        printf("Case #%d:\n", kase);
        scanf("%d %d %d", &L, &T, &n);
        for(int i = 0; i < n; i++)
        {
            int p, d;
            char c;
            scanf("%d %c", &p, &c);
            d = (c == 'L' ? -1 : 1);
            before[i] = (Ant){i, p, d};
            after[i] = (Ant){0, p+T*d, d};//这里id是未知的
        }

        //计算ordor数组,每只蚂蚁其实都会呆在自己的区间里！
        sort(before, before+n);//按蚂蚁的位置排序
        //（排在第i位置的蚂蚁的输入id）的（order数组值）是终态的第i只蚂蚁
        //因为输入id的蚂蚁在“穿过”别的蚂蚁后会改变id
        for(int i = 0; i < n; i++) order[before[i].id] = i;

        //计算终态
        sort(after, after+n);
        for(int i = 0; i < n-1; i++)
            if(after[i].p == after[i+1].p) after[i].d = after[i+1].d = 0;

        //输出结果
        for(int i = 0; i < n; i++)
        {
            int a = order[i];
            if(after[a].p < 0 || after[a].p > L) printf("Fell off\n");
            else printf("%d %s\n", after[a].p, dirName[after[a].d+1]);
        }
        printf("\n");
    }
    return 0;
}
