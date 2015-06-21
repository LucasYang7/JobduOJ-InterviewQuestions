#include<stdio.h>
#define MAX 1501
 
/**
* 返回3个数中的最小值
* @param long long a  第一个数
* @param long long b  第二个数
* @param long long c  第三个数
* @return long long  三个数中的最小值
*/
long long getMinOfThreeNumbers(long long a,long long b,long long c)
{
  long long min = a;
  if(b < min)
     min = b;
  if(c < min)
     min = c;
  return min;
}
 
/**
* 获取前n个丑数
* @param longlong uglyNumber[] 用于存放丑数的数组
* @return void;
*/
void getUglyNumbers(long long uglyNumber[],int n)
{
   int i;
   int indexOfUglyNumber = 1;          // 丑数数组对应的下标
   int indexOfTwo = 1;                 // 与2对应的乘数的在丑数数组中的下标
   int indexOfThree = 1;               // 与3对应的乘数的在丑数数组中的下标
   int indexOfFive = 1;                // 与5对应的乘数的在丑数数组中的下标
   long long curUglyNumber;            // 当前生成的丑数
   long long curUglyNumberOfTwo;       // 由与2相乘得到的丑数
   long long curUglyNumberOfThreee;    // 由与3相乘得到的丑数
   long long curUglyNumberOfFive;      // 由与5相乘得到的丑数
   uglyNumber[1] = 1;                  // 第1个丑数是1
   for(i = 2;i <= 1500; i++)
   {
      curUglyNumberOfTwo = 2 * uglyNumber[indexOfTwo];
      curUglyNumberOfThreee = 3 * uglyNumber[indexOfThree];
      curUglyNumberOfFive = 5 * uglyNumber[indexOfFive];
      // 从当前3个候选中，选择最小的一个做为新的丑数
      curUglyNumber = getMinOfThreeNumbers(curUglyNumberOfTwo,curUglyNumberOfThreee,curUglyNumberOfFive);
      uglyNumber[++indexOfUglyNumber] = curUglyNumber;
      // 更新各个乘数的下标
      while(2 * uglyNumber[indexOfTwo] <= curUglyNumber)
      {
          indexOfTwo++;
      }
      while(3 * uglyNumber[indexOfThree] <= curUglyNumber)
      {
          indexOfThree++;
      }
      while(5 * uglyNumber[indexOfFive] <= curUglyNumber)
      {
          indexOfFive++;
      }
 
   }
}
 
/**
*  打印第n个丑数
*  @param long long uglyNumber[]  存储丑数的数组
*  @param int n  n表示打印第n个丑数
*  @return void
*/
void printNthUglyNumber(long long uglyNumber[],int n)
{
   printf("%lld\n",uglyNumber[n]);
}
 
int main()
{
    long long uglyNumber[MAX];             // 存放丑数
    int n;
    getUglyNumbers(uglyNumber,1500);       // 获取前1500个丑数
    while(EOF != scanf("%d",&n))
    {
       printNthUglyNumber(uglyNumber,n);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46439983
****************************************************************/