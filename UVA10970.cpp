/* UVA 10970 Big Chocolate 2017-11-29

切一块m行n列的巧克力，要切成1×1，要切几刀，每刀只可以切一块巧克力

Sample Input
2 2
1 1
1 5

Sample Output
3
0
4

分析：
观察规律，可得切的刀数总是m*n-1

*/

#include<cstdio>

int main(void)
{
    int m, n;
    while(scanf("%d %d", &m, &n) == 2) printf("%d\n", m*n - 1);
    return 0;
}
