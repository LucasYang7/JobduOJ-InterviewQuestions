#include<stdio.h>
 
/**
*  打印从1到最大的N位数
*  @param N  输入的N代表10进制数的位数
*  @return void
*/
void printOneToNBit(int N)
{
 int number = 1;
 int i,j;
 for(i = 1;i <= N;i++)
 {
     number = 10 * number;
 }
 
 // 输出[1,10^N - 1]
 for(j = 1;j < number;j++)
 {
    printf("%d\n",j);
 }
}
 
int main()
{
    int N;
    scanf("%d",&N);
    printOneToNBit(N);
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46357991
****************************************************************/
