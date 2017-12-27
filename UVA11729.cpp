/* UVA 11729 2017-11-21

有n个部下，每个部下都要完成一个任务。
第i个部下需要画Bi分钟交代任务，然后它会花Ji分钟完成。
不能同时交代任务，但可以同时执行任务。
求所有任务完成的最短时间。

第一行输入部下个数n(1<=n<=1000)
n行B J(1<=B,J<=10000)
输入n=0结束

Sample Input
3
2 5
3 2
2 1
3
3 3
4 4
5 5
0

Sample Output
Case 1: 8
Case 2: 15

解法：
可以用贪心解，按执行时间从大到小排序，然后依次执行


 */

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct job
{
    int j, b;//注意这里的顺序，压入的数据是按这里先后顺序压入的
    //运算符重载。不要忘记const修饰。用于可以按j对结构体进行排序
    bool operator < (const job & x) const {return j > x.j;}
};

int main(void)
{
    int n, kase = 1;
    while(scanf("%d", &n) == 1 && n)
    {
        vector<job> v;
        int b, j;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &b, &j);
            v.push_back((job){j,b});//把数据压入数组
        }
        sort(v.begin(), v.end());//对数组按j排序
        int s = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            s += v[i].b;//当前任务的开始执行时间
            ans = max(ans, s+v[i].j);//更新任务执行完毕时的最晚时间
        }
        printf("Case %d: %d\n", kase, ans);
        kase++;
    }
    return 0;
}
