// 第一种解法
#include<stdio.h>
 
/**
*  打印和等于S的连续序列
*  @param begin  连续序列的开始值
*  @param end  连续序列的终止值
*  @return void
*/
void printContinueSequence(int begin,int end)
{
    int i = begin;
    printf("%d",i);
    for(i = begin + 1;i <= end;i++)
    {
        printf(" %d",i);
    }
    printf("\n");
}
 
/**
*  获取和等于S的连续序列
*  @param S  用户输入的S
*  @return numberOfSequence 和等于S的连续序列的个数
*/
int getContinueSequenceEqualsS(int S)
{
  int numberOfSequence = 0;
  int begin = 1;                // 连续序列的起点
  int end = 2;                  // 连续序列的终点
  int middle = S/2;             // 因为连续序列的长度最少为2，而begin + end <= S，所以begin最大的值为S/2
  int sum = begin + end;        // sum是连续序列[begin,end]的和
  while(begin <= middle)
  {
      if(sum == S)          // 如果当前序列和等于S，则输出连续序列[begin,end]
      {
          printContinueSequence(begin,end);
          sum = sum - begin;
          begin++;
          numberOfSequence++;
      }
      else if(sum < S)      // 如果当前的连续序列和小于S，则将end的下一个元素添加到sum中
      {
          end++;
          sum += end;
      }
      else                  // 如果当前的连续序列和大于S,则将begin踢出连续序列
      {
          sum = sum - begin;
          begin++;
      }
  }
  return numberOfSequence;
}
 
int main()
{
    int S;
    int number;
    while(EOF != scanf("%d",&S) && S >= 0)
    {
       number = getContinueSequenceEqualsS(S);
       if(0 == number)
       {
           printf("Pity!\n");
       }
       printf("#\n");
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46472621
****************************************************************/