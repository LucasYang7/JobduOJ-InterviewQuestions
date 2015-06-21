#include<stdio.h>
 
/**
* 计算出青蛙跳上一个n级的台阶总共有多少种跳法
* f(n) = f(n-1) + f(n-2) + ... + f(2) + f(1) + f(0) ---->  f(n) = 2*(f(n-1))   // n >= 2
* @param jumpMethods  用于保存跳台阶的跳法数目
* @return void
*/
void getNumberOfSuperJumpSteps(long long * jumpMethods)
{
    int i;
    jumpMethods[1] = 1;
    for(i = 2;i <= 50;i++)
    {
       jumpMethods[i] = 2 * jumpMethods[i - 1];
    }
}
 
int main()
{
    int n;
    long long jumpMethods[51];               // 记录跳台阶的方法数目
    getNumberOfSuperJumpSteps(jumpMethods);
    while(EOF != scanf("%d",&n))
    {
        printf("%lld\n",jumpMethods[n]);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46343171
****************************************************************/
