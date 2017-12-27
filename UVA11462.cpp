/* UVA 11462 Age Sort 2017-11-29

给定许多居民的年龄（1～100），把它们按照从小到大输出

输入：
第一行：居民总数n（0<n<=2 000 000）
第二行：n个整数（不小于1不大于100的整数）
（输入文件大约有25MB，而内存限制只有2MB）

输出：按从小到大顺序输出数字，用空格隔开

Sample Input
5
3 4 2 1 5
5
2 3 2 3 1
0

Sample Output
1 2 3 4 5
1 2 2 3 3

分析：因为内存太小无法使用快速排序，可以用计数排序

*/

#include<cstdio>
#include<cstring>

int main(void)
{
    int n, x, c[101];
    while(scanf("%d", &n) == 1 && n)
    {
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; i++) {scanf("%d", &x); c[x]++;}
        int first = 1;
        for(int i = 1; i <=100; i++)
            for(int j = 0; j < c[i]; j++)
            {
                if(!first) printf(" ");
                first = 0;
                printf("%d", i);
            }
        printf("\n");
    }
    return 0;
}
