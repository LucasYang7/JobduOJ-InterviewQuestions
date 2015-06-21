#include<stdio.h>
 
/**
* 统计区间[1,n]中1出现的次数
* @param n  输入的整数n
* @return count  返回区间[1,n]中1出现的次数
*/
long long countOneFromOneToN(int n)
{
  long long count = 0;   // 统计1 ~ n中1出现的次数
  if(n < 1)
      return count;
  else
  {
      int tempN = n;                   // 用于保存处理过程中的n
      int lowBits = 0;                 // 整数n中比当前进制位更低的低位部分
      int highBits = n;                // 整数n中比当前进制位更高的高位部分
      int currentDecimalBit = 0;       // 整数n当前被处理数位所对应的数字，最先处理个位上的数字
      int currentDecimalWeight = 1;    // 整数n当前正在处理的进制位，最先处理个位
      while(tempN > 0)
      {
          highBits = n / (10 * currentDecimalWeight);   // 求高位部分
          if(currentDecimalWeight > 1)
          {
              lowBits = n % currentDecimalWeight;       // 求低位部分
          }
          currentDecimalBit = tempN % 10;               // 求正在被处理的当前位
 
          // 将当前位与1进行比较，然后分类讨论统计1出现的次数
          if(currentDecimalBit > 1)
          {
              count += (highBits + 1) * currentDecimalWeight;
          }
          else if(currentDecimalBit == 1)
          {
              count += highBits * currentDecimalWeight + lowBits + 1;
          }
          else
          {
              count += highBits * currentDecimalWeight;
          }
          tempN = tempN / 10;
          currentDecimalWeight = 10 * currentDecimalWeight; // 跳到n的下一个高位，例如从个位跳到十位
      }
      return count;
  }
}
 
/**
* 交换两个整数
* @param a  整数a的地址
* @param b  整数b的地址
* @return void
*/
void swap(int * a,int * b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}
 
int main()
{
    long long result;                  // [a,b]区间中1出现的次数
    long long CountA;                  // [1,a-1]区间中1出现的次数
    long long CountB;                  // [1,b]区间中1出现的次数
    int a,b;
    while(EOF != scanf("%d%d",&a,&b))
    {
        if(a > b)                      // 如果输入的a比b大，则需要交换两个数
        {
            swap(&a,&b);
        }
        CountA  = countOneFromOneToN(a - 1);      // 统计[1,a-1]区间中1出现的次数
        CountB  = countOneFromOneToN(b);          // 统计[1,b]区间中1出现的次数
        result = CountB - CountA;
        printf("%lld\n",result);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46439491
****************************************************************/