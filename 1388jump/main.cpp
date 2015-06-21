#include<stdio.h>
 
/**
* 计算n(1<=n<=70)级台阶所对应的跳法数目
* @param jumpMethods  用于保存跳台阶的跳法数目
* @return void
*/
void getNumberOfJumpStepMethods(long long * jumpMethods)
{
  int i;
  jumpMethods[0] = 1;
  jumpMethods[1] = 1;
  for(i = 2;i <= 70;i++)
  {
     jumpMethods[i] = jumpMethods[i - 2] + jumpMethods[i - 1];
  }
}
 
int main()
{
    int n;
    long long jumpMethods[71];            // 记录跳台阶的跳法数目
    getNumberOfJumpStepMethods(jumpMethods);
    while(EOF != scanf("%d",&n))
    {
        printf("%lld\n",jumpMethods[n]);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46342847
****************************************************************/