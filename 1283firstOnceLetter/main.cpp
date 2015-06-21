#include<stdio.h>
#include<string.h>
#define MAX 10000
// 输入的字符串
char inputStrings[MAX];
// 定义的字母结构体
typedef struct Node
{
  int index;         // 字母在字符串第一次出现时所对应的下标
  int times;         // 字母在字符串中出现的次数
}LetterNode;
 
/**
* 初始化字母结点
* @param letterNode[]  用于保存大写字母信息的结构体数组
* @return void
*/
void initLetterNode(LetterNode letterNode[])
{
  int i;
  for(i = 0;i < 26;i++)
  {
      letterNode[i].index = 10001;
      letterNode[i].times = 0;
  }
}
 
/**
* 统计每个字母在字符串中出现的次数和第一次出现的下标
* @param inputString[]  输入的字符串
* @param len  输入字符串的长度
* @param letterNode[]  用于保存每个字母出现次数和第一次出现下标的数组
* @return void
*/
void countTimes(char inputString[],int len,LetterNode letterNode[])
{
  int i = 0;
  int letter;
  while(i < len)
  {
      letter = inputString[i] - 'A';        // 将字符串中的大写字母转换为LetterNode数组对应的下标
      if(0 == letterNode[letter].times)
      {
          letterNode[letter].index = i;     // 记录字母在字符串中第一次出现的下标
      }
      letterNode[letter].times++;
      i++;
  }
}
 
/**
* 寻找字符串中第一个只出现一次的字母
* @param letterNode[]  用于保存每个字母出现次数和第一次出现下标的数组
* @return firstIndex 返回第一个只出现一次的字符下标
*/
int getFirstOnceLetterIndex(LetterNode letterNode[])
{
  int firstIndex = -1;
  int i,j;
  LetterNode tempNode;
  // 对LetterNode数组按照index域的大小从小到大依次进行排序
  for(i = 0;i < 26;i++)
  {
      for(j = i;j < 26;j++)
      {
        if(letterNode[j].index < letterNode[i].index)
        {
           tempNode = letterNode[i];
           letterNode[i] = letterNode[j];
           letterNode[j] = tempNode;
        }
      }
  }
  // 找出第一个只出现一次的字符在字符串中的下标
  for(i = 0;i < 26;i++)
  {
      if(1 == letterNode[i].times)
      {
          firstIndex = letterNode[i].index;
          break;
      }
  }
  return firstIndex;
}
 
int main()
{
    LetterNode letterNode[26];   // 存储26个大写字母的信息
    int len;
    int firstOnceIndex;
    while(EOF != scanf("%s",inputStrings))
    {
       initLetterNode(letterNode);
       len = strlen(inputStrings);
       countTimes(inputStrings,len,letterNode);
       firstOnceIndex = getFirstOnceLetterIndex(letterNode);
       printf("%d\n",firstOnceIndex);
    }
    return 0;
}
 
/**************************************************************
解题报告：http://blog.csdn.net/pengyan0812/article/details/46440069
****************************************************************/