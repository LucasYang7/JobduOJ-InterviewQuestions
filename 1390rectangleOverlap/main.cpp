#include<stdio.h>
#define MAX 71
 
long long overlapMethods[MAX];         // 用64位整形存储数据，防止溢出
 
/**
* 将矩阵覆盖转化为跳楼梯的问题
* 将1个2 * 1小矩阵横着摆等价于跳1级楼梯,将2个2 * 1小矩阵竖着摆等价于跳2级楼梯
* 然后抽象为斐波那契数列
* @return void
*/
void getFibonacci()
{
 int i;
 overlapMethods[0] = 1;
 overlapMethods[1] = 1;
 for(i = 2;i <= 70;i++)
 {
     overlapMethods[i] = overlapMethods[i - 1] + overlapMethods[i - 2];
 }
}
 
int main()
{
    int n;
    getFibonacci();
    while(EOF != scanf("%d",&n))
    {
        printf("%lld\n",overlapMethods[n]);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46345539
****************************************************************/