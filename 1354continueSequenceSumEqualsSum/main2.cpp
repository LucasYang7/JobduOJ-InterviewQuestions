// 第二种解法
#include<stdio.h>
#include<math.h>
 
/**
* 打印和等于S的连续序列
* @param begin  连续序列的开始值
* @param end  连续序列的终止值
* @return void
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
* 获取和等于S的连续序列
* @param S  用户输入的S
* @return numberOfSequence  和等于S的连续序列的个数
*/
int getContinueSequenceEqualsS(int S)
{
   int numberOfSequence = 0;
   int n;       // 和等于S的连续序列的长度
   int a1;      // 和等于S的连续序列的第1项
   for(n = sqrt(2 * S); n >= 2; n--) // n越大，a1越小，因此n的初始值为sqrt(2 * S)，最终值为2
   {
     if((2 * S) % n == 0)  // 保证2S / n是整数
     {
         if(0 == (2 * S / n - n + 1) % 2)  // 保证a1是整数
         {
           a1 = (2 * S / n - n + 1) / 2;
           numberOfSequence++;
           printContinueSequence(a1,a1 + n - 1);
         }
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