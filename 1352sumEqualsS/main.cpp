#include<stdio.h>
#define MAX 1000001
 
int number[MAX];                // 用于保存整数的数组
 
/**
* 输入长度为n的整形数组
* @param n  表示数组的长度
* @return void
*/
void inputNumberArray(int n)
{
  int i;
  for(i = 0;i < n;i++)
  {
      scanf("%d",&number[i]);
  }
}
 
/**
* 寻找数组中两个和等于S的数字
* @param n  数组的长度
* @param k  k表示要求的两数之和
* @return void
*/
void findTwoNumberSumEqualsS(int n,int k)
{
  int left,right;
  //令left = 0,right = n - 1，这样当找到number[left] + number[right]) == k，可以保证number[left]*number[right]的值最小
  left = 0,right = n - 1;
  while(left <= right)
  {
      // 如果两个数之和等于k，则直接输出这两个
      if((number[left] + number[right]) == k)
      {
          break;
      }
      // 如果两个数之和小于k，则令left++
      else if((number[left] + number[right]) < k)
      {
          left++;
      }
      // 如果两个数之和大于k,则令right--
      else
      {
          right--;
      }
  }
  if(left < right)
     printf("%d %d\n",number[left],number[right]);
  else
     printf("-1 -1\n");
}
 
int main()
{
    int n,k;
    while(EOF != scanf("%d%d",&n,&k))
    {
       inputNumberArray(n);
       findTwoNumberSumEqualsS(n,k);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46472479
****************************************************************/
