#include<stdio.h>
#define MAX 1000001
 
int number[MAX];
 
/**
* 输入整形数组
* @param n 输入的数组大小
* @return void
*/
void inputArray(int n)
{
  int i;
  for(i = 0;i < n;i++)
  {
      scanf("%d",&number[i]);
  }
}
 
/**
* 二分查找
* @param k  待查找的元素
* @param n  数组的长度
* @return position  待查元素在数组中的位置，如果查找不成功，则返回-1
*/
int binarySearch(int k,int n)
{
  int position = -1;
  int left = 0,right = n - 1;
  int middle;
  while(left <= right)
  {
    middle = (left + right) / 2;
    if(k == number[middle])
    {
        position = middle;
        break;
    }
    else if(k > number[middle])
    {
        left = middle + 1;
    }
    else
    {
        right = middle - 1;
    }
  }
  return position;
}
 
/**
* 统计k在有序数组中出现的次数。以k为中心，向数组两边同时查找与k相等的元素
* @param k  待查找的元素
* @param position  k在数组中的位置
* @param n  数组的长度
* @return count 数字k在有序数组中出现的次数
*/
int countKinSortArray(int k,int position,int n)
{
   int count = 0;
   int i = position - 1;
   int j = position;
   // 向数组的左边查找与k相等的元素，为了避免查找过程中出现数组越界，先判断i是否大于等于0，再让number[i]与k进行比较
   while(i >= 0 && number[i] == k)
   {
       i--;
       count++;
   }
   // 向数组的右边查找与k相等的元素
   while(j < n && number[j] == k)
   {
       j++;
       count++;
   }
   return count;
}
 
int main()
{
    int n,m,k;
    int position;    // 待查元素在有序数组中的位置
    int count;       // 待查元素在有序数组中出现的次数
    while(EOF != scanf("%d",&n))
    {
    inputArray(n);
    scanf("%d",&m);
    while(m--)
    {
       scanf("%d",&k);
       count = 0;
       position = binarySearch(k,n);
       if(-1 != position)
       {
         count = countKinSortArray(k,position,n);
       }
       printf("%d\n",count);
    }
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46454157
****************************************************************/