/* UVA 10340 All in All 2017-11-29

输入两个字符串s和t，判断是否可以从t中删除0或多个字符（其他字符顺序不变）得到字符s

Sample Input
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

Sample Output
Yes
No
Yes
No

分析：
简单暴力通过

*/

#include<cstdio>

char s[101000], t[101000];
int main(void)
{
    while(scanf("%s %s", s, t) == 2)
    {
        int j = 0;
        for(int i = 0; s[j] && t[i]; i++)
            if(s[j] == t[i]) j++;
        if(s[j]) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
