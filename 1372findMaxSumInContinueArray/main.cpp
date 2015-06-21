#include<stdio.h>
 
/**
*  获取具有最大和的连续子向量的向量和，向量起点和向量终点
*  思路：从头到尾扫描向量，遇到以下两种情况后进行相应的处理:
*  (1)如果当前子向量的和大于之前子向量的最大和，则更新连续子向量的最大和，子向量起点，子向量终点
*  (2)如果当前子向量的和小于0，将该连续子向量看成一个等于其和的负数，
*     然后将下一个向量元素做为新连续子向量的起点，继续寻找有可能具有最大和的连续子向量
*  @param n  输入向量的长度
*  @return void
*/
void getMaxSumInContinueArray(int n)
{
   int start,end;           // 和最大的连续子向量的起点和终点
   int potentialStart;      // 连续子向量的潜在起点
   int maxSum;              // 连续子向量的最大和
   int sum;                 // 实时存放某个连续子向量的和
   int number;              // 向量中的元素
   int i = 0;
   maxSum = -1001;          // 因为输入向量中每个数字的取值范围是[-1000,1000]，所以maxSum的初始值为-1001
   sum = 0;
   potentialStart = 0;
   while(i < n)
   {
      scanf("%d",&number);
      sum += number;
      if(sum > maxSum)              // (1)如果和大于当前的最大和，则更新最大和maxSum和start,end
      {
         maxSum = sum;
         start = potentialStart;    // 将潜在的起点赋值为新的起点
         end = i;
      }
      if(sum < 0)  // (2)当某个连续子向量的和小于0时，更新potentialStart和sum
      {
          potentialStart = i + 1;   // 更新潜在起点potentialStart为当前的下一个位置
          sum = 0; // 更新sum = 0,重新开始寻找下一个有可能具有最大和的连续子向量
      }
      i++;
   }
   printf("%d %d %d\n",maxSum,start,end);
}
 
int main()
{
 
    int n;
    while(EOF != scanf("%d",&n) && 0 != n)
    {
        getMaxSumInContinueArray(n);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46439223
****************************************************************/
