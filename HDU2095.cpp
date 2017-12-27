/* HDU 2095 2017-11-28

有一个正整数数组，其中只有一个数出现里奇数次，输出此数
最后输入0代表结束

输入：
第一行输入n(1<=n<=1 000 000)
第二行输入n个数，每个数都不超过2^31

Sample Input
5
1 1 3 2 2
3
1 2 1
0

Sample Output
3
2
  
use scanf to avoid Time Limit Exceeded

分析：
因为出了一个数外其他数都出现了两次，可以用异或运算（不同为1,同为0）

*/

#include<cstdio>

int main(void)
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        int temp, ans = 0;
        while(n--) {scanf("%d", &temp); ans ^= temp;}
        printf("%d\n", ans);
    }
    return 0;
}
