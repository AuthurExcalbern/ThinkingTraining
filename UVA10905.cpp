/* UVA 10382 Watering Grass 2017-11-29

给n个正整数，求怎么拼接成一个最大数

输入：
第一行：n(1<=n<=50)
n个整数
输入结束标志为n = 0

输出：
输出可以得到的最大整数

Sample Input
4
123 124 56 90
5
123 124 56 90 9
5
9 9 9 9 9
0

Sample Output
9056124123
99056124123
99999


分析：
这题可以用string类比较方便的完成

*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int l;
    string s;
    //把字符串s从小到大排序
    bool operator < (const node & p) const { return s < p.s; }
};

node s[55];

int main(void)
{
    int n;
    while(cin >> n && n)
    {
        int maxn = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> s[i].s;
            s[i].l = s[i].s.length();
            maxn = max(maxn, s[i].l);
        }
        maxn++;
        for(int i = 0; i < n; i++)//防止WA，再复制一次字符串
        {
            string p = s[i].s;
            while(s[i].s.length() < maxn) s[i].s += p;
        }
        sort(s, s+n);//排序
        string ss;
        for(int i = n-1; i >= 0; i--)//拼合
            for(int j = 0; j < s[i].l; j++)
                ss += s[i].s[j];
        cout << ss << endl;
    }
    return 0;
}
