#include<stdio.h>
#define MAX 100000
int number[MAX];
 
/**
* 输入数组
* @param n  数组的长度
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
* 获取数组中出现次数超过一半的候选元素
* @param n  数组的长度
* @return candidate  返回数组中出现次数超过一半的候选元素
*/
int getCandidateFromArray(int n)
{
  int candidate = number[0];             // 用于保存候选元素
  int count = 1;                         // 用于标记候选元素的数目
  int i;
  for(i = 1;i < n;i++)
  {
      if(candidate == number[i])
      {
        count++;                         // 如果数组中第i个元素等于候选元素，则记录候选元素的个数增加1个
      }
 
      else
      {
        count--;                         // 如果数组中第i个元素不等于候选元素，则记录候选元素的个数减少1个
        if(0 == count)
        {
             candidate = number[i];      // 如果候选元素的个数为0，则更新候选元素为number[i]
             count = 1;                  // 要记住给count赋值为 1
        }
      }
  }
  return candidate;
}
 
/**
* 判断候选元素在数组中出现的次数是否真的超过一半
* @param candidate  候选元素
* @param n  数组的长度
* @return bool  如果候选元素在数组中出现的次数超过一半则返回true,否则返回false
*/
bool checkCandidate(int candidate,int n)
{
  int i;
  int count = 0;
  for(i = 0;i < n;i++)
  {
    if(candidate == number[i])
     count++;
  }
  if(count > (n - count))                 // 表示候选元素在数组中出现的次数超过了一半
     return true;
  else
     return false;
}
 
int main()
{
    int n;
    int candidate;
    bool isCandidateValid;              // 判断候选元素是否合法
    while(EOF != scanf("%d",&n))
    {
      inputArray(n);
      candidate = getCandidateFromArray(n);
      isCandidateValid = checkCandidate(candidate,n);
      if(true == isCandidateValid)
      {
         printf("%d\n",candidate);
      }
      else
      {
         printf("-1\n");
      }
    }// while
    return 0;
}
 
/**************************************************************
http://blog.csdn.net/pengyan0812/article/details/46424003
****************************************************************/
