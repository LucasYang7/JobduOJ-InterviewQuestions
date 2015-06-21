#include<stdio.h>
 
/**
* 输入抽出的扑克牌序列
* @param poker  用于存储扑克牌输入序列的数组
* @param n  抽出的扑克牌的张数
* @return void
*/
void inputPoker(int poker[],int n)
{
  int i;
  for(i = 0;i < n;i++)
  {
      scanf("%d",&poker[i]);
  }
}
 
/**
* 判断抽出的扑克牌是不是顺子
* @param poker  抽出的扑克牌
* @param n  抽出的扑克牌的张数
* @return bool 如果抽出的扑克牌是顺子，则返回true,否则返回false。
*/
bool isPokerStraight(int poker[],int n)
{
  bool isStraight;
  int i,j;
  int temp;
  int countKing = 0;
  int gap;                          // 排好序的普通扑克牌序列中相邻两张扑克牌之间的间距
  int gapSum = 0;                   // 排除大小王以后剩余普通牌的间距之和
  // 对抽出的扑克牌进行排序
  for(i = n - 1;i > 0;i--)
  {
      for(j = 0;j < i;j++)
      {
        if(poker[j] > poker[j + 1])
        {
          temp = poker[j];
          poker[j] = poker[j + 1];
          poker[j + 1] = temp;
        }
      }
  }
  // 统计牌中大小王的张数
  i = 0;
  while(i < n && 0 == poker[i])
  {
      i++;
      countKing++;
  }
  // 统计抽出的扑克牌中的间距
  while(i < n - 1)
  {
      gap = poker[i + 1] - poker[i];
      if(gap > 0)
      {
         gapSum = gapSum + gap;
      }
      else                          // 排除大小王后的剩余普通牌中出现了相同的牌，无法构成顺子
      {
         isStraight = false;
         return isStraight;
      }
      i++;
  }
  // n - countKing - 1是排除大小王后剩余普通扑克牌组成顺子的合法间距
  // gapSum - countKing是将大小王插入到普通扑克牌序列后还剩下的间距
  // 一张大小王能够消除1个间距
  // 例如：2 与 4 相差2个间距，插入一张大小王并将该大小王看成是3后，可以认为2与4之间只相差一个间距了
  if(gapSum - countKing > n - countKing - 1)
     isStraight = false;
  else
     isStraight = true;
  return isStraight;
}
 
int main()
{
    int n;
    int poker[15];
    bool isStraight;
    while(EOF != scanf("%d",&n) && 0 != n)
    {
       inputPoker(poker,n);
       isStraight = isPokerStraight(poker,n);
       if(true == isStraight)
          printf("So Lucky!\n");
       else
          printf("Oh My God!\n");
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46482403
****************************************************************/