/* UVA 11384 2017-11-26

给定正整数n，求用最少操作次数将序列1～n中所有数都变成0

Input
Input consists of several lines each with N such that 1 ≤ N ≤ 1, 000, 000, 000. Input will be terminated
by end of file.

Output
For each N output L in separate lines.

Sample Input
1
2
3

Sample Output
1
2
2

解法：
每次减去最小数于最大数的平均数，可得到：f(n)=f(n/2)+1，边界是f(1)=1

 */

#include<cstdio>

int f(int n) { return n == 1 ? 1 : f(n/2) + 1; }

int main(void)
{
    int n;
    while(scanf("%d", &n) == 1) printf("%d\n", f(n));
    return 0;
}
