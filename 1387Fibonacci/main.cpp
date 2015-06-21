#include<stdio.h>
#define N 70
 
long long fibonacci[71];        // 用long long存放fibonacci数列 这样能防止结果溢出
 
/**
* 采用迭代的办法求斐波那契数列
* @param n  表示要求出斐波那契数列的前n项
* @return void
*/
void getFibonacci(int n)
{
    int i;
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(i = 2;i <= n;i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}
 
int main()
{
    int n;
    getFibonacci(N);
    while(EOF != scanf("%d",&n))
    {
        printf("%lld\n",fibonacci[n]);      // 注意long long 输出为 lld
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46342445
****************************************************************/