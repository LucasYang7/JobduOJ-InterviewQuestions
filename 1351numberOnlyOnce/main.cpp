#include<stdio.h>
#define MAX 1000001
int number[MAX];
 
/**
* 输入含有n个元素的整形数组
* @param n  表示数组的元素个数
* @return void
*/
void inputNumberArray(int n)
{
   int i;
   for(i = 0;i < n;i++)
      scanf("%d",&number[i]);
}
 
/**
* 找到两个数字对应二进制中的最低不同位
* @param exclusiveOr  数组中所有元素异或得到的结果，因为除了两个元素之外，
*                     其余元素都出现了两次，所以这个异或结果等价于两个只
*                     出现一次的数字异或所得的结果
* @return int  两个只出现一次的数字的二进制最低不同位所对应的十进制数
*/
int getDifferentBit(int exclusiveOr)
{
  int differentBit = 1;
  while(0 == (exclusiveOr & 1))
  {
     differentBit = differentBit << 1;
     exclusiveOr = exclusiveOr >> 1;
  }
  return differentBit;
}
 
/**
* 找到数组中两个只出现一次的数字
* @param n  表示数组的元素个数
* @return void
*/
void findTwoNumberOnlyOnce(int n)
{
  int exclusiveOr = 0;       // 保存异或运算所得到的结果
  int differenceBit;
  int i;
  int a = 0,b = 0;
  int temp;
  for(i = 0;i < n;i++)
  {
     exclusiveOr = exclusiveOr ^ number[i];
  }
  differenceBit = getDifferentBit(exclusiveOr);
  // 根据number[i]的第log2differenceBit位的数字是否为1，可以将数组中的元素分为两类：
  // 一类数字的二进制与a的第log2differenceBit位相同，这类数字与a进行异或;
  // 另一类的数字的二进制则与b的第log2differenceBit位相同,这类数字与b进行异或。
  // 而与a同类的数字都各自出现了两次，这些数字两两异或后结果为0，最后的异或结果中只剩下a,同理可以得到b。
  for(i = 0;i < n;i++)
  {
      if(0 != (number[i] & differenceBit))
      {
          a = a ^ number[i];
      }
      else
      {
          b = b ^ number[i];
      }
  }
  // 如果a > b，则将a与b进行交换，保证最后的结果是a < b。
  if(a > b)
  {
    temp = a;
    a = b;
    b = temp;
  }
  printf("%d %d\n",a,b);
}
 
int main()
{
    int n;
    while(EOF != scanf("%d",&n))
    {
       inputNumberArray(n);
       findTwoNumberOnlyOnce(n);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46454581
****************************************************************/