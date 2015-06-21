#include<stdio.h>
#include<math.h>
#include<float.h>
 
/**
*  求浮点数的整数次幂
*  @param base  浮点数
*  @param exponent  整数次幂
*  @return void
*/
void doublePower(double base,int exponent)
{
    double result;
    result = pow(base,exponent);
    if(result > DBL_MAX)                     // 表示结果大于double的最大值 则输出INF
    {
       printf("INF\n");
    }
    else
    {
       // 按照指数格式输出浮点数，底数保留两位
       // 注意不同的编译器对于科学计数法格式输出中指数位数的差别
       printf("%.2lef\n",result);
    }
}
 
int main()
{
    int T;
    double base;
    int exponent;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%d",&base,&exponent);
        doublePower(base,exponent);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46357631
****************************************************************/